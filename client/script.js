document.addEventListener('DOMContentLoaded', function () {
    const footerParagraph = document.getElementById('build_version');

    const filePath = '../src/VERSION.txt';

    fetch(filePath)
        .then(response => response.text())
        .then(data => {
            footerParagraph.textContent = data;
        })
        .catch(error => {
            console.error('Error:', error);
        });
});
