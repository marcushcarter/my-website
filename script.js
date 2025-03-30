// LOAD THE CUSTOM ELEMENTS

class Navbar extends HTMLElement {
    connectedCallback() {
        this.innerHTML = `
            <nav class="nav-bar">
                <div class="menu-container">
                    <div class="menu"><i class="fa-solid fa-bars"></i></div>
                    <div class="dropdown">
                        <a href="index.html">Home</a>
                        <a href="engine-download.html">Download Ballistic Engine</a>
                        <a href="games.html">Games</a>
                        <a href="">Link</a>
                        <a href="">Link</a>
                        <a href="">Link</a>
                        <a href="">Link</a>
                        <a href="">Link</a>
                        <a href="">Link</a>
                        <a href="">Link</a>
                    </div>
                </div>
                <a href="index.html" class="website-name">Ballistic Studios</a>
                <a href="" class="login-btn">Login</a>
            </nav>
        `;
    }
}

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
                    <a href="index.html">Home</a>
                    <a>Store</a>
                    <a>About</a>
                    <a href="mailto:marcoose408@gmail.com" target=_self>Contact us</a>
                    <a>Contribute</a>
                    <a>Privacy Policy</a>
                </div>
                <a class="extra-links">Ballistic Studios © 2024</a>
            </footer>
        `;
    }
}

class SearchBar extends HTMLElement {
    connectedCallback() {
        this.innerHTML = `
            <a class="search-bar">
                <input type="text" id="search-bar" placeholder="Search..." oninput="filterItems()">
            </a>
        `;
    }
}

customElements.define('custom-navbar', Navbar);
customElements.define('custom-footer', Footer);
customElements.define('custom-searchbar', SearchBar);

// SEARCH BAR FUNCTIONS

function filterItems() {
    let input = document.getElementById("search-bar").value.toLowerCase();
    let items = document.querySelectorAll("#search-objects li");

    items.forEach(item => {
        let itemName = item.getAttribute("data-name").toLowerCase();
        
        if (itemName.includes(input)) {
            item.style.display = ""; 
        } else {
            item.style.display = "none";
        }
    });
}