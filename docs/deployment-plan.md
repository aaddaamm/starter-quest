# Vercel Deployment Plan

This document provides instructions for deploying the "Starter Quest" WebAssembly application to [Vercel](https://vercel.com).

Vercel is a cloud platform for static sites and serverless functions that is well-suited for hosting this project. Since our WebAssembly build process produces a set of static files (`.html`, `.js`, `.wasm`), it can be easily deployed on Vercel's global CDN.

## Configuration for Vercel

The project has been pre-configured for a seamless Vercel deployment. Here are the key files involved:

1.  **`build-wasm.sh`**: This build script has been modified to be CI/CD friendly. It compiles the C++ code into WebAssembly without starting a local web server, which allows it to run in Vercel's build environment.

2.  **`vercel.json`**: This configuration file tells Vercel everything it needs to know to deploy the application. It specifies:
    *   **Framework**: Set to `"other"` since this is not a standard Node.js-based framework.
    *   **Install Command**: `npm install vercel-emscripten-setup`. This command installs a community-provided package that sets up the Emscripten SDK on Vercel's build servers.
    *   **Build Command**: `npx vercel-emscripten-setup && chmod +x ./build-wasm.sh && ./build-wasm.sh`. This command first sets up Emscripten, then makes our build script executable, and finally runs the script to compile the C++ code.
    *   **Output Directory**: `"wasm"`. This tells Vercel that the static files to be served are located in the `wasm` directory.

## Deployment Steps

Follow these steps to deploy the application:

1.  **Sign up for a Vercel Account**: If you don't already have one, sign up for a free account at [vercel.com](https://vercel.com). It's recommended to sign up with your Git provider (GitHub, GitLab, or Bitbucket).

2.  **Install the Vercel CLI**: The Vercel Command Line Interface (CLI) allows you to deploy your project directly from your terminal. Install it globally using npm:
    ```bash
    npm install -g vercel
    ```

3.  **Log in to Vercel**: Connect the Vercel CLI to your account by running:
    ```bash
    vercel login
    ```
    This will prompt you to enter the email address associated with your Vercel account.

4.  **Deploy the Project**: Navigate to the root of the `starter-quest` project in your terminal and run the deployment command:
    ```bash
    vercel
    ```

The Vercel CLI will guide you through the remaining setup questions. It will automatically detect the `vercel.json` configuration and use it for the build.

*   When prompted to link to a project, you can create a new one.
*   The project name and other settings can be configured as you see fit.

Once the deployment process is complete, Vercel will provide you with a unique URL (e.g., `https://starter-quest-xxxx.vercel.app`) where your live application can be accessed.

## Continuous Deployment (Optional but Recommended)

For a more robust workflow, you can connect your Git repository directly to Vercel. This will enable continuous deployment, meaning Vercel will automatically redeploy your application every time you push a change to your repository.

You can set this up from the Vercel dashboard by importing your Git repository. Vercel will automatically detect the `vercel.json` file and configure the build settings.