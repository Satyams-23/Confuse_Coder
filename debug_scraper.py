import requests
from bs4 import BeautifulSoup

# Step 1: URL of the Constitution of India
url = "https://www.indiacode.nic.in/acts-in-force/constitution-of-india/"

# Step 2: Send GET request
res = requests.get(url)
print(f"Status Code: {res.status_code}")
print(f"Content Length: {len(res.text)}")

if res.status_code != 200:
    print("Failed to fetch page")
    exit()

# Step 3: Parse HTML
soup = BeautifulSoup(res.text, "html.parser")

# Let's examine the structure first
print("\n=== Page Title ===")
print(soup.title.string if soup.title else "No title found")

print("\n=== Looking for potential article containers ===")
# Try different selectors
divs_with_class = soup.find_all("div", class_=True)
print(f"Found {len(divs_with_class)} divs with classes")

# Print some class names to see what's available
class_names = set()
for div in divs_with_class[:20]:  # Check first 20
    if div.get('class'):
        class_names.add(' '.join(div.get('class')))
print(f"Sample class names: {list(class_names)[:10]}")

# Look for headings that might contain article numbers
headings = soup.find_all(['h1', 'h2', 'h3', 'h4', 'h5', 'h6'])
print(f"\n=== Found {len(headings)} headings ===")
for i, heading in enumerate(headings[:10]):
    print(f"{i+1}. {heading.name}: {heading.get_text(strip=True)[:100]}")

# Look for text that contains "Article"
article_text = soup.find_all(text=lambda text: text and "article" in text.lower())
print(f"\n=== Found {len(article_text)} text elements containing 'article' ===")
for i, text in enumerate(article_text[:5]):
    print(f"{i+1}. {text.strip()[:100]}")

# Check if the page is actually loading the constitution content
print(f"\n=== Page content preview ===")
print(res.text[:1000])
