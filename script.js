
// LOAD CUSTOM NAVIGATION BAR FOR ROOT AND SUBFOLDER

class Navbar extends HTMLElement {
    connectedCallback() {
        this.innerHTML = `
            <nav class="nav-bar">
                <div class="menu-container">
                    <div class="menu"><i class="fa-solid fa-bars icon"></i></div>
                    <div class="dropdown">
                        <a href="/search.html"><i class="fa-solid fa-magnifying-glass" style="font-size: 18px;"></i></a>
                        <a href="/index.html">Home</a>
                        <a href="/websites.html">Websites</a>
                        <a href="projects/projects.html">Lessons and Projects</a>
                        <a href="/about.html">About Us</a>
                    </div>
                </div>
                <a href="/index.html"><img class="navbar-logo" src="/resources/logo-full.png"></a>
                <a href="/login.html" class="login-btn">Log In</a>
            </nav>
        `;
    }
}
customElements.define('custom-navbar', Navbar);

// LOAD CUSTOM FOOTER FOR ROOT AND SUBFOLDER

class Footer extends HTMLElement {
    connectedCallback() {
        this.innerHTML = `
            <div style="height: 50px;"></div>
            <footer>
                <div class="social-links">
                    <a href="https://instagram.com/ballisticstudiosofficial" target="_blank"><i class="fa-brands fa-instagram"></i></a>
                    <a href="https://www.tiktok.com/@ballisticstudiosofficial" target="_blank"><i class="fa-brands fa-tiktok"></i></a>
                    <a href="https://github.com/marcushcarter" target="_blank"><i class="fa-brands fa-github"></i></a> 
                </div>
                <div class="extra-links">
                    <a href="/about.html">About</a>
                    <a href="#" onclick="scrolltopage('/about.html', 'contact-us'); return false;">Contact us</a>
                    <a href="/contribute.html">Contribute</a>
                    <a>Privacy Policy</a>
                </div>
                <a class="copyright">© Ballistic Studios 2024</a>
            </footer>
        `;
    }
}
customElements.define('custom-footer', Footer);

// LOAD CUSTOM SEARCH BAR

class SearchBar extends HTMLElement {
    connectedCallback() {
        this.innerHTML = `
            <a class="search-bar">
                <input type="text" id="search-bar" placeholder="Search..." oninput="filterItems()">
            </a>
        `;
    }
}
customElements.define('custom-searchbar', SearchBar);

// SEARCH BAR FUNCTIONS

function filterItems() {
    let input = document.getElementById("search-bar").value.toLowerCase().trim();
    let items = document.querySelectorAll("#search-objects li");

    items.forEach(item => {
        let itemName = item.getAttribute("data-name").toLowerCase();
        let searchTerms = input.split(/\s+/); // Split input into words (spaces)

        // Check if all search terms exist somewhere in the data-name
        let matchesAll = searchTerms.every(term => itemName.includes(term));

        if (matchesAll) {
            item.style.display = "";
        } else {
            item.style.display = "none";
        }
    });
}

// MENU BUTTON BEING CLICKABLE ON MOBILE PHONES

const menuIcon = document.querySelector('.menu');
const dropdown = document.querySelector('.dropdown');

menuIcon.addEventListener('click', function(event) {
    event.stopPropagation(); // Prevent click event from propagating
    dropdown.style.display = dropdown.style.display === 'block' ? 'none' : 'block';
});

document.addEventListener('click', function(event) {
    if (!menuIcon.contains(event.target)) {
        dropdown.style.display = 'none';
    }
});

// EAMIL FORM

function showThanks() {
    document.querySelector("form").style.display = "none";
    document.getElementById("thank-you").style.display = "block";
    return true;
}

// GO TO PAGE AND SCROLL TO ELEMENT ID

function scrolltopage(pageUrl, elementId) {
    // Use a query parameter instead of a hash
    const url = `${pageUrl}?scrollTo=${elementId}`;
    window.location.href = url;
}

window.addEventListener('DOMContentLoaded', () => {
    const params = new URLSearchParams(window.location.search);
    const elementId = params.get('scrollTo');

    if (elementId) {
        const target = document.getElementById(elementId);
        if (target) {
            const offset = 135; // pixels to go up
            const elementTop = target.getBoundingClientRect().top + window.pageYOffset;
            const scrollPosition = elementTop - offset;

            window.scrollTo({
                top: scrollPosition,
                behavior: 'smooth'
            });
        }
    }
});

// SCROLL TO ELEMENT ID

function scrollto(elementId) {
    const OFFSET = 135;
  
    if (!elementId) {
      console.warn("scrollToElementById: No element ID provided.");
      return;
    }
  
    const targetElement = document.getElementById(elementId);
    if (!targetElement) {
      console.warn(`scrollToElementById: No element found with ID "${elementId}"`);
      return;
    }
  
    const elementPosition = targetElement.getBoundingClientRect().top + window.pageYOffset;
    const offsetPosition = elementPosition - OFFSET;
  
    window.scrollTo({
      top: offsetPosition,
      behavior: 'smooth'
    });
  }
  