// Initialisation EmailJS
(function() {
    emailjs.init("S-nVJVb47dQmJ8T2F"); // Remplace par ta clé publique
})();

function Envoyer(event) {
    // Empêcher l'envoi classique du formulaire
    event.preventDefault();
    console.log('Fonction Envoyer appelée');
    
    // Récupérer les données du formulaire
    const formData = {
        name: document.getElementById('name').value,
        email: document.getElementById('email').value,
        subject: document.getElementById('subject').value,
        message: document.getElementById('message').value
    };

    // Validation basique
    if (!formData.name || !formData.email || !formData.message) {
        showMessage('errormessage', 'Veuillez remplir tous les champs obligatoires.');
        return;
    }

    // Envoi via EmailJS
    emailjs.send("service_8tiuoig", "template_wgty22e", formData)
        .then(function(response) {
            showMessage('sendmessage', 'Message envoyé avec succès !');
            resetForm();
        }, function(error) {
            showMessage('errormessage', "Erreur lors de l'envoi. Réessayez.");
            console.error('EmailJS Error:', error);
        });
}

function showMessage(elementId, message) {
    const element = document.getElementById(elementId);
    element.innerHTML = message;
    element.style.display = 'block';
    
    // Cacher après 5 secondes
    setTimeout(() => {
        element.style.display = 'none';
    }, 5000);
}

function resetForm() {
    document.querySelector('.contactForm').reset();
}

// Validation en temps réel
document.addEventListener('DOMContentLoaded', function() {
    const inputs = document.querySelectorAll('.contactForm input, .contactForm textarea');
    
    inputs.forEach(input => {
        input.addEventListener('blur', function() {
            validateField(this);
        });
    });
});

function validateField(field) {
    const validationElement = field.parentElement.querySelector('.validation');
    
    if (!field.value.trim()) {
        validationElement.innerHTML = 'Ce champ est requis';
        return false;
    }
    
    if (field.type === 'email' && !isValidEmail(field.value)) {
        validationElement.innerHTML = 'Email invalide';
        return false;
    }
    
    validationElement.innerHTML = '';
    return true;
}

function isValidEmail(email) {
    const re = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
    return re.test(email);
}