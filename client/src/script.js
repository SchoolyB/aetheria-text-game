// Function to fetch and display version information
function displayVersionInfo() {
    fetch('../../version.json') // Assuming version.json is in the same directory
        .then(response => response.json())
        .then(data => {
            // Access the version data from the JSON
            const projectVersion = data.game_version;
            const websiteVersion = data.website_version;

            // Create HTML elements to display the data
            const versionInfo = document.getElementById('version-info');
            const projectVersionElement = document.createElement('p');
            projectVersionElement.textContent = `Current Game Build: ${projectVersion}`;
            const websiteVersionElement = document.createElement('p');
            websiteVersionElement.textContent = `Current Website Build: ${websiteVersion}`;

            // Append the elements to the page
            versionInfo.appendChild(projectVersionElement);
            versionInfo.appendChild(websiteVersionElement);
        })
        .catch(error => {
            console.error('Error fetching version data:', error);
        });
}

// Call the function to display version information
displayVersionInfo();
