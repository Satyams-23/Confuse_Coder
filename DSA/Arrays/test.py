import requests
from bs4 import BeautifulSoup

# Step 1: URL of the Constitution of India on IndiaCode
url = "https://www.indiacode.nic.in/show-data?actid=AC_CEN_5_23_00001_195026_1517807320564"

# Step 2: Send GET request
res = requests.get(url)
if res.status_code != 200:
    print("Failed to fetch page")
    exit()

# Step 3: Parse HTML
soup = BeautifulSoup(res.text, "html.parser")

# Step 4: Inspect the structure manually first
# IndiaCode usually has each Article inside <div class="section">
sections = soup.find_all("div", class_="section")

print(f"Found {len(sections)} sections/articles")

# Step 5: Extract data
data = []

for sec in sections:
    # Article number/title
    article_header = sec.find("h3")
    if not article_header:
        continue  # skip if header not found

    article_no = article_header.get_text(strip=True)
    
    # Article text
    paragraphs = sec.find_all("p")
    text = " ".join([p.get_text(strip=True) for p in paragraphs])

    data.append({
        "articleNo": article_no,
        "text": text,
        # Optional: Detect part dynamically if site provides <h2> or <div class="part">
        "part": "Part III - Fundamental Rights"
    })

# Step 6: Preview first 5 articles
for i, article in enumerate(data[:5]):
    print(f"{i+1}. {article['articleNo']}\n{article['text'][:200]}...\n")  # Print first 200 chars

# Step 7: Optionally save to JSON
import json
with open("articles_preview.json", "w", encoding="utf-8") as f:
    json.dump(data, f, ensure_ascii=False, indent=2)
