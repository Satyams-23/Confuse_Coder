import requests
from bs4 import BeautifulSoup
import json

print("Starting Constitution scraper with working URL...")

# Step 1: Use the working URL for Constitution of India
url = "https://www.indiacode.nic.in/handle/123456789/15240?lang=en&locale=en"

try:
    print("Making request to Constitution website...")
    
    # Step 2: Send GET request with timeout and headers to mimic a browser
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36'
    }
    
    res = requests.get(url, timeout=15, headers=headers)
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
    data = []
    
    # Method 1: Look for divs with "article" in class name
    article_divs = soup.find_all("div", class_=lambda x: x and "article" in str(x).lower())
    print(f"Found {len(article_divs)} divs with 'article' in class")
    
    # Method 2: Look for elements containing "Article" text
    article_elements = soup.find_all(text=lambda text: text and "Article" in text and text.strip())
    print(f"Found {len(article_elements)} text elements containing 'Article'")
    
    # Method 3: Look for headings that might be articles
    headings = soup.find_all(['h1', 'h2', 'h3', 'h4', 'h5', 'h6'])
    print(f"Found {len(headings)} headings")
    
    # Print some sample content to understand structure
    print("\n=== Sample headings ===")
    for i, heading in enumerate(headings[:10]):
        print(f"{i+1}. {heading.name}: {heading.get_text(strip=True)[:100]}")
    
    # Method 4: Look for patterns like "Article 1", "Article 2", etc.
    import re
    article_pattern = re.compile(r'Article\s+\d+', re.IGNORECASE)
    
    # Find all text that matches article pattern
    all_text = soup.get_text()
    article_matches = article_pattern.findall(all_text)
    print(f"\nFound {len(set(article_matches))} unique article references: {list(set(article_matches))[:10]}")
    
    # Try to extract content around articles
    paragraphs = soup.find_all("p")
    print(f"Found {len(paragraphs)} paragraphs")
    
    # Look for paragraphs that contain article references
    article_paragraphs = []
    for p in paragraphs:
        text = p.get_text(strip=True)
        if article_pattern.search(text) and len(text) > 50:
            article_paragraphs.append(text)
    
    print(f"Found {len(article_paragraphs)} paragraphs containing articles")
    
    # Extract data from article paragraphs
    for i, para_text in enumerate(article_paragraphs[:20]):  # Limit to first 20
        # Try to extract article number
        article_match = article_pattern.search(para_text)
        article_no = article_match.group() if article_match else f"Article {i+1}"
        
        data.append({
            "articleNo": article_no,
            "text": para_text,
            "part": "Constitution of India"
        })
    
    # If still no data, try to get any meaningful content
    if not data:
        print("No article-specific content found. Extracting general content...")
        for i, p in enumerate(paragraphs[:10]):
            text = p.get_text(strip=True)
            if len(text) > 30:  # Only meaningful paragraphs
                data.append({
                    "articleNo": f"Content {i+1}",
                    "text": text,
                    "part": "Constitution of India"
                })
    
    print(f"\nExtracted {len(data)} items")
    
    # Step 6: Print first 5 items
    for i, item in enumerate(data[:5]):
        print(f"\n{i+1}. {item['articleNo']}")
        print(f"Text: {item['text'][:300]}...")
    
    # Save to JSON
    with open("constitution_articles.json", "w", encoding="utf-8") as f:
        json.dump(data, f, ensure_ascii=False, indent=2)
    
    print(f"\nSaved {len(data)} items to constitution_articles.json")
    
    # Also save the HTML for inspection
    with open("constitution_page.html", "w", encoding="utf-8") as f:
        f.write(res.text)
    print("Saved HTML to constitution_page.html for inspection")

except requests.exceptions.Timeout:
    print("Request timed out. The website might be slow or unreachable.")
except requests.exceptions.RequestException as e:
    print(f"Network error: {e}")
except Exception as e:
    print(f"Error: {e}")
    import traceback
    traceback.print_exc()

print("Script completed.")
