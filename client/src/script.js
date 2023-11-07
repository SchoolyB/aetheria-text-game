import versionData from '../../version.json';

// Get references to the HTML elements by their IDs
const gameVersionElement = document.getElementById('game-version');
const websiteVersionElement = document.getElementById('website-version');

// Update the content of the HTML elements with the fetched data
gameVersionElement.textContent = `Current Game Build: ${versionData.game_version}`;
websiteVersionElement.textContent = `Current Website Build: ${versionData.website_version}`;
