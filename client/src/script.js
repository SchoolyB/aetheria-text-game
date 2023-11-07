import versionData from '../../version.json';

// Get references to the HTML elements by their IDs
const gameVersionElement = document.getElementById('game-version');
const websiteVersionElement = document.getElementById('website-version');

// Update the content of the HTML elements with the fetched data
gameVersionElement.textContent = `${versionData.game_version}`;
websiteVersionElement.textContent = `${versionData.website_version}`;

