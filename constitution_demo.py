import requests
from bs4 import BeautifulSoup
import json

print("=== Constitution Scraper Demo ===\n")

# This demonstrates how your original script would work with proper data structure
# Since the actual websites have complex structures, here's a demo with sample data

# Simulate what your original script would extract
sample_constitution_data = [
    {
        "articleNo": "Article 1",
        "text": "India, that is Bharat, shall be a Union of States. The States and the territories thereof shall be as specified in the First Schedule. The territory of India shall comprise the territories of the States, the Union territories specified in the First Schedule and such other territories as may be acquired.",
        "part": "Part I - The Union and its Territory"
    },
    {
        "articleNo": "Article 14", 
        "text": "The State shall not deny to any person equality before the law or the equal protection of the laws within the territory of India.",
        "part": "Part III - Fundamental Rights"
    },
    {
        "articleNo": "Article 15",
        "text": "The State shall not discriminate against any citizen on grounds only of religion, race, caste, sex, place of birth or any of them. No citizen shall, on grounds only of religion, race, caste, sex, place of birth or any of them, be subject to any disability, liability, restriction or condition with regard to access to shops, public restaurants, hotels and places of public entertainment.",
        "part": "Part III - Fundamental Rights"
    },
    {
        "articleNo": "Article 19",
        "text": "All citizens shall have the right to freedom of speech and expression; to assemble peaceably and without arms; to form associations or unions; to move freely throughout the territory of India; to reside and settle in any part of the territory of India; and to practise any profession, or to carry on any occupation, trade or business.",
        "part": "Part III - Fundamental Rights"
    },
    {
        "articleNo": "Article 21",
        "text": "No person shall be deprived of his life or personal liberty except according to procedure established by law.",
        "part": "Part III - Fundamental Rights"
    }
]

print("=== Your Original Script Logic (Demo) ===")
print("Here's how your script would work with properly structured data:\n")

# Step 6: Print first 5 articles (as in your original script)
for i, article in enumerate(sample_constitution_data[:5]):
    print(f"{i+1}. {article['articleNo']}")
    print(f"Part: {article['part']}")
    print(f"Text: {article['text'][:200]}...\n")

# Save to JSON (as in your original script)
with open("sample_constitution_articles.json", "w", encoding="utf-8") as f:
    json.dump(sample_constitution_data, f, ensure_ascii=False, indent=2)

print(f"Saved {len(sample_constitution_data)} sample articles to sample_constitution_articles.json")

print("\n=== Real Website Analysis ===")
print("The actual Constitution websites have complex structures that require:")
print("1. Different HTML selectors")
print("2. JavaScript rendering (some content is loaded dynamically)")
print("3. Navigation through multiple pages")
print("4. Different parsing logic for different sections")

# Let's try to get some real data from the working website
print("\n=== Attempting Real Data Extraction ===")

try:
    url = "https://www.constitutionofindia.net/read/"
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36'
    }
    
    res = requests.get(url, timeout=10, headers=headers)
    if res.status_code == 200:
        soup = BeautifulSoup(res.text, "html.parser")
        
        # Look for links that might lead to actual articles
        links = soup.find_all('a', href=True)
        article_links = []
        
        for link in links:
            href = link.get('href', '')
            text = link.get_text(strip=True)
            if 'article' in text.lower() or 'part' in text.lower():
                article_links.append((href, text))
        
        print(f"Found {len(article_links)} potential article links:")
        for i, (href, text) in enumerate(article_links[:10]):
            print(f"{i+1}. {text[:50]} -> {href}")
        
        # Try to extract any actual article content
        import re
        article_pattern = re.compile(r'Article\s+(\d+)', re.IGNORECASE)
        
        # Look in all text for article patterns
        all_text = soup.get_text()
        matches = article_pattern.findall(all_text)
        
        print(f"\nFound {len(set(matches))} unique article numbers referenced: {sorted(set(matches), key=int)[:10]}")
        
        # Save the HTML for manual inspection
        with open("constitution_page_for_analysis.html", "w", encoding="utf-8") as f:
            f.write(res.text)
        print("Saved HTML to constitution_page_for_analysis.html for manual inspection")
        
except Exception as e:
    print(f"Error in real data extraction: {e}")

print("\n=== Summary ===")
print("Your original script logic is correct!")
print("The challenge is finding websites with the right HTML structure.")
print("Consider using:")
print("1. Selenium for JavaScript-rendered content")
print("2. Different selectors based on actual website structure")
print("3. Multiple data sources")
print("4. Manual inspection of HTML structure first")

print("\n=== Demo completed ===")
