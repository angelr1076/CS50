const email = document.getElementById("email");

(function() {
  emailjs.init("user_ac8YrWHXluHjOjhDqWaqX");
})();

window.onload = function() {
  document
    .getElementById("contact-form")
    .addEventListener("submit", function(event) {
      event.preventDefault();
      // generate the contact number value
      this.contact_number.value = (Math.random() * 100000) | 0;
      emailjs.sendForm("gmail", "template_tqlrfTYo", this);
      setInterval(() => {
        email.innerHTML = "Email sent.";
      }, 800);
    });
};
