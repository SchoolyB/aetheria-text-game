// module.exports = {
//   //...
//  content: ["./src/**/*.{html,js}"],
//   // add daisyUI plugin
  
//   //...
// }

/** @type {import('tailwindcss').Config} */
module.exports = {
  content: [
    './src/**/*.{html,js}',
    './**/*.{html,js}',
  ],
  plugins: [require("daisyui")]
  // ...
}