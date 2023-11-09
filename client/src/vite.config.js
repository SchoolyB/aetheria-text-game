import { defineConfig } from 'vite';

export default defineConfig({

  build: {
    rollupOptions: {
      input: {
        main: './index.html',
        media: './media.html',
        patch_notes: './patch_notes.html',
      },
    },
  },
});
