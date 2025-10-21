import requests
from bs4 import BeautifulSoup

print("Testing web scraping...")

# Test with a simple website first
test_url = "https://httpbin.org/html"
try:
    response = requests.get(test_url)
    print(f"Test request status: {response.status_code}")
    
    # Now try the actual Constitution URL
    url = "https://www.indiacode.nic.in/acts-in-force/constitution-of-india/"
    res = requests.get(url)
    print(f"Constitution URL status: {res.status_code}")
    print(f"Response length: {len(res.text)}")
    
    if res.status_code == 200:
        soup = BeautifulSoup(res.text, "html.parser")
        print(f"Page title: {soup.title.string if soup.title else 'No title'}")
        
        # Look for any links or content
        links = soup.find_all('a')
        print(f"Found {len(links)} links")
        
        # Print first few links
        for i, link in enumerate(links[:5]):
            print(f"Link {i+1}: {link.get('href', 'No href')} - {link.get_text(strip=True)[:50]}")
    else:
        print(f"Failed to access Constitution URL. Status: {res.status_code}")
        
except Exception as e:
    print(f"Error: {e}")
