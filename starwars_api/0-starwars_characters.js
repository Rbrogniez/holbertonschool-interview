#!/usr/bin/node

const request = require('request');

/**
 * Returns the name of a Star Wars character given their URL
 * @param {string} characterUrl - The URL of the character
 * @returns {Promise<string>} - A promise that resolves to the character's name
 */
function getName (characterUrl) {
  return new Promise((resolve, reject) => {
    request.get(characterUrl, (error, response, body) => {
      if (error) {
        reject(error);
      } else {
        resolve(JSON.parse(body).name);
      }
    });
  });
}

/**
 * Displays the names of all characters in a Star Wars film
 * @returns {Promise<void>} - A promise that resolves when all names have been displayed
 */
const displayData = async () => {
  try {
    const filmId = process.argv[2];
    request.get(`https://swapi-api.hbtn.io/api/films/${filmId}`, async (error, response, body) => {
      if (error) {
        console.log('Found error');
      } else {
        const names = await Promise.all(JSON.parse(body).characters.map(character => getName(character)));
        names.forEach(name => console.log(name));
      }
    });
  } catch (err) {
    console.log('Found error');
  }
};

displayData();
