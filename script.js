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
                        <a href="">Store</a>
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
            <footer class="footer">
                <div class="footer-container">
                    <div class="footer-links">
                        <a href="about.html">About Us</a>
                        <a href="contact.html">Contact</a>
                        <a href="privacy-policy.html">Privacy Policy</a>
                    </div>
                    <div class="footer-socials">
                        <a href="https://facebook.com/ballisticstudios"><i class="fa-brands fa-facebook"></i></a>
                        <a href="https://twitter.com/ballisticstudios"><i class="fa-brands fa-twitter"></i></a>
                        <a href="https://instagram.com/ballisticstudios"><i class="fa-brands fa-instagram"></i></a>
                    </div>
                </div>
                <p class="footer-note">© 2025 Ballistic Studios. All rights reserved.</p>
            </footer>
        `;
    }
}

customElements.define('custom-navbar', Navbar);
customElements.define('custom-footer', Footer);