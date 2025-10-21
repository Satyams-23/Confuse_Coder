import requests
from bs4 import BeautifulSoup

# Step 1: URL of the Constitution of India
url = "https://www.indiacode.nic.in/acts-in-force/constitution-of-india/"

# Step 2: Send GET request
res = requests.get(url)
if res.status_code != 200:
    print("Failed to fetch page")
    exit()

# Step 3: Parse HTML
soup = BeautifulSoup(res.text, "html.parser")

# Step 4: Find all articles
articles = soup.find_all("div", class_="article")  # Adjust class based on actual structure

# Step 5: Extract data
data = []
for art in articles:
    article_no = art.find("h3").get_text(strip=True) if art.find("h3") else "No Article Number"
    text = " ".join([p.get_text(strip=True) for p in art.find_all("p")])
    data.append({
        "articleNo": article_no,
        "text": text,
        "part": "Part III - Fundamental Rights"  # Adjust dynamically if possible
    })

# Step 6: Print first 5 articles
for i, article in enumerate(data[:5]):
    print(f"{i+1}. {article['articleNo']}\n{article['text'][:200]}...\n")  # Print first 200 chars

# Optionally, save to JSON
import json
with open("articles.json", "w", encoding="utf-8") as f:
    json.dump(data, f, ensure_ascii=False, indent=2)
