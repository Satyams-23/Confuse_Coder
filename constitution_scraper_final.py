import requests
from bs4 import BeautifulSoup
import json
import re

print("=== Constitution of India Article Scraper ===\n")

# Step 1: Try multiple URLs for Constitution of India
urls_to_try = [
    "https://www.constitutionofindia.net/constitution_of_india",
    "https://www.mea.gov.in/Images/pdf1/Part1.pdf",
    "https://www.indiacode.nic.in/handle/123456789/15240",
    "https://www.constitutionofindia.net/"
]

headers = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36'
}

def extract_constitution_articles(soup, url):
    """Extract articles from the parsed HTML"""
    data = []
    
    print(f"Analyzing content from: {url}")
    
    # Method 1: Look for specific article patterns
    article_pattern = re.compile(r'Article\s+(\d+)', re.IGNORECASE)
    
    # Get all text content
    all_text = soup.get_text()
    
    # Find all article references
    article_matches = article_pattern.findall(all_text)
    unique_articles = list(set(article_matches))
    print(f"Found references to {len(unique_articles)} unique articles: {sorted(unique_articles, key=int)[:10]}")
    
    # Method 2: Look for structured content
    # Try to find headings that contain articles
    headings = soup.find_all(['h1', 'h2', 'h3', 'h4', 'h5', 'h6'])
    print(f"Found {len(headings)} headings")
    
    article_headings = []
    for heading in headings:
        heading_text = heading.get_text(strip=True)
        if article_pattern.search(heading_text):
            article_headings.append((heading, heading_text))
    
    print(f"Found {len(article_headings)} headings containing articles")
    
    # Method 3: Look for divs or sections that might contain articles
    potential_article_containers = []
    
    # Try different selectors
    selectors_to_try = [
        "div[class*='article']",
        "section[class*='article']", 
        "div[class*='constitution']",
        "section[class*='constitution']",
        ".article",
        ".constitution-article"
    ]
    
    for selector in selectors_to_try:
        elements = soup.select(selector)
        if elements:
            print(f"Found {len(elements)} elements with selector: {selector}")
            potential_article_containers.extend(elements)
    
    # Method 4: Look for paragraphs that contain article content
    paragraphs = soup.find_all("p")
    print(f"Found {len(paragraphs)} paragraphs")
    
    article_paragraphs = []
    for p in paragraphs:
        text = p.get_text(strip=True)
        if article_pattern.search(text) and len(text) > 50:
            article_paragraphs.append(text)
    
    print(f"Found {len(article_paragraphs)} paragraphs containing articles")
    
    # Extract data from what we found
    if article_headings:
        for heading, heading_text in article_headings[:10]:
            article_match = article_pattern.search(heading_text)
            article_no = f"Article {article_match.group(1)}" if article_match else heading_text
            
            # Try to find the content following this heading
            next_elements = []
            current = heading.find_next_sibling()
            while current and len(next_elements) < 3:
                if current.name in ['p', 'div']:
                    text = current.get_text(strip=True)
                    if text and len(text) > 20:
                        next_elements.append(text)
                current = current.find_next_sibling()
            
            content = " ".join(next_elements) if next_elements else heading_text
            
            data.append({
                "articleNo": article_no,
                "text": content,
                "part": "Constitution of India"
            })
    
    elif article_paragraphs:
        for i, para_text in enumerate(article_paragraphs[:10]):
            article_match = article_pattern.search(para_text)
            article_no = article_match.group() if article_match else f"Article {i+1}"
            
            data.append({
                "articleNo": article_no,
                "text": para_text,
                "part": "Constitution of India"
            })
    
    elif potential_article_containers:
        for i, container in enumerate(potential_article_containers[:10]):
            text = container.get_text(strip=True)
            article_match = article_pattern.search(text)
            article_no = article_match.group() if article_match else f"Content {i+1}"
            
            data.append({
                "articleNo": article_no,
                "text": text[:500],  # Limit length
                "part": "Constitution of India"
            })
    
    # If still no data, extract general content
    if not data:
        print("No specific articles found. Extracting general content...")
        for i, p in enumerate(paragraphs[:10]):
            text = p.get_text(strip=True)
            if len(text) > 30:
                data.append({
                    "articleNo": f"Content {i+1}",
                    "text": text,
                    "part": "Constitution of India"
                })
    
    return data

# Try each URL
successful_data = []
for url_index, url in enumerate(urls_to_try):
    print(f"\n=== Trying URL {url_index + 1}: {url} ===")
    
    try:
        print("Making request...")
        
        # Send GET request with redirect following
        res = requests.get(url, timeout=15, headers=headers, allow_redirects=True)
        print(f"Final URL: {res.url}")
        print(f"Status Code: {res.status_code}")
        print(f"Response length: {len(res.text)}")
        
        if res.status_code == 200:
            # Parse HTML
            soup = BeautifulSoup(res.text, "html.parser")
            
            # Get page info
            title = soup.title.string if soup.title else "No title found"
            print(f"Page title: {title}")
            
            # Extract articles
            data = extract_constitution_articles(soup, res.url)
            
            if data:
                print(f"\nExtracted {len(data)} items from this URL")
                successful_data.extend(data)
                
                # Print first few items
                for i, item in enumerate(data[:3]):
                    print(f"\n{i+1}. {item['articleNo']}")
                    print(f"Text: {item['text'][:200]}...")
                
                # Save individual results
                filename = f"constitution_data_url_{url_index + 1}.json"
                with open(filename, "w", encoding="utf-8") as f:
                    json.dump(data, f, ensure_ascii=False, indent=2)
                print(f"Saved data to {filename}")
                
                # If we got good data, we can break here
                if len(data) > 5:  # If we got substantial data
                    print(f"\nGot substantial data from URL {url_index + 1}. Stopping search.")
                    break
            else:
                print("No meaningful data extracted from this URL")
        else:
            print(f"Failed to fetch page. Status: {res.status_code}")
            
    except requests.exceptions.Timeout:
        print("Request timed out.")
    except requests.exceptions.RequestException as e:
        print(f"Network error: {e}")
    except Exception as e:
        print(f"Error: {e}")

# Save combined results
if successful_data:
    with open("constitution_articles_final.json", "w", encoding="utf-8") as f:
        json.dump(successful_data, f, ensure_ascii=False, indent=2)
    
    print(f"\n=== FINAL RESULTS ===")
    print(f"Total items extracted: {len(successful_data)}")
    print(f"Saved to: constitution_articles_final.json")
    
    # Print summary
    print(f"\n=== Sample Results ===")
    for i, item in enumerate(successful_data[:5]):
        print(f"\n{i+1}. {item['articleNo']}")
        print(f"Text: {item['text'][:300]}...")
else:
    print("\nNo data extracted from any URL.")
    print("This might be due to:")
    print("1. Website structure changes")
    print("2. Anti-scraping measures")
    print("3. Need for JavaScript rendering")
    print("4. Different content organization")

print("\n=== Script completed ===")
