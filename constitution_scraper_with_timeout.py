import requests
from bs4 import BeautifulSoup
import json

print("Starting Constitution scraper...")

# Step 1: URL of the Constitution of India
url = "https://www.indiacode.nic.in/acts-in-force/constitution-of-india/"

try:
    print("Making request to Constitution website...")
    
    # Step 2: Send GET request with timeout
    res = requests.get(url, timeout=10)
    print(f"Status Code: {res.status_code}")
    print(f"Response length: {len(res.text)}")
    
    if res.status_code != 200:
        print(f"Failed to fetch page. Status: {res.status_code}")
        exit()
    
    # Step 3: Parse HTML
    soup = BeautifulSoup(res.text, "html.parser")
    
    # Let's examine what we actually got
    print(f"Page title: {soup.title.string if soup.title else 'No title found'}")
    
    # Step 4: Try to find articles with different selectors
    print("Searching for articles...")
    
    # Try different approaches to find articles
    articles = []
    
    # Method 1: Look for divs with "article" in class name
    article_divs = soup.find_all("div", class_=lambda x: x and "article" in str(x).lower())
    print(f"Found {len(article_divs)} divs with 'article' in class")
    
    # Method 2: Look for elements containing "Article" text
    article_elements = soup.find_all(text=lambda text: text and "Article" in text)
    print(f"Found {len(article_elements)} text elements containing 'Article'")
    
    # Method 3: Look for headings that might be articles
    headings = soup.find_all(['h1', 'h2', 'h3', 'h4', 'h5', 'h6'])
    print(f"Found {len(headings)} headings")
    
    # Print some sample content to understand structure
    print("\n=== Sample headings ===")
    for i, heading in enumerate(headings[:5]):
        print(f"{i+1}. {heading.name}: {heading.get_text(strip=True)[:100]}")
    
    # Try to extract some basic structure
    data = []
    
    # If we found article divs, process them
    if article_divs:
        for art in article_divs:
            article_no = art.find(["h1", "h2", "h3", "h4", "h5", "h6"])
            article_no = article_no.get_text(strip=True) if article_no else "No Article Number"
            text = " ".join([p.get_text(strip=True) for p in art.find_all("p")])
            data.append({
                "articleNo": article_no,
                "text": text,
                "part": "Unknown"
            })
    
    # If no articles found, let's save what we have
    if not data:
        print("No articles found with current selectors. Saving page structure for analysis...")
        # Save the HTML for manual inspection
        with open("constitution_page.html", "w", encoding="utf-8") as f:
            f.write(res.text)
        print("Saved HTML to constitution_page.html")
        
        # Try to extract any meaningful content
        paragraphs = soup.find_all("p")
        print(f"Found {len(paragraphs)} paragraphs")
        
        # Save first few paragraphs as sample data
        for i, p in enumerate(paragraphs[:10]):
            data.append({
                "articleNo": f"Paragraph {i+1}",
                "text": p.get_text(strip=True),
                "part": "Sample Content"
            })
    
    print(f"\nExtracted {len(data)} items")
    
    # Step 6: Print first 5 items
    for i, item in enumerate(data[:5]):
        print(f"\n{i+1}. {item['articleNo']}")
        print(f"Text: {item['text'][:200]}...")
    
    # Save to JSON
    with open("articles.json", "w", encoding="utf-8") as f:
        json.dump(data, f, ensure_ascii=False, indent=2)
    
    print(f"\nSaved {len(data)} items to articles.json")

except requests.exceptions.Timeout:
    print("Request timed out. The website might be slow or unreachable.")
except requests.exceptions.RequestException as e:
    print(f"Network error: {e}")
except Exception as e:
    print(f"Error: {e}")
    import traceback
    traceback.print_exc()

print("Script completed.")
