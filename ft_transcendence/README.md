# ft_transcendence

ft_transcendence is a project at [Codam](codam.nl) which requires that we build an online platform to play [Pong.](https://en.wikipedia.org/wiki/Pong)

The backend must be built using [NestJS](https://nestjs.com/), the [frontend](https://en.wikipedia.org/wiki/Frontend_and_backend) in any [TypeScript](https://www.typescriptlang.org/) framework of your choice and the database must be [PostgreSQL.](https://www.postgresql.org/) For the [frontend](https://en.wikipedia.org/wiki/Frontend_and_backend), the chosen option was [React](https://reactjs.org/), due to its popularity and extensive documentation.

There are no restraints in regards to external libraries and the website but it needs to be a [single-page application.](https://en.wikipedia.org/wiki/Single-page_application) It should be compatible with [Google Chrome](https://www.google.com/intl/en-US/chrome/).

The user must log in using the OAuth system of [42 intranet](https://intra.42.fr/) and be able to enable a [two-factor authentication](https://authy.com/what-is-2fa/) method.

Overall, the platform should have a ranking system, chat channels, private messages, profile editing, view users status and add other members as friends.

The platform should have a ranking system, chat channels, direct messaging and allow, user status changes, friend features and some profile customization options.

The main purpose is to play an implementation of [Pong](https://en.wikipedia.org/wiki/Pong), as if it was [1972.](https://www.youtube.com/watch?v=fiShX2pTz9A) all over again There should be a few customization options such as custom maps or power-ups but the user should still be able to play the original version.

Finally, the server structure must be containerized using [docker](https://www.docker.com/) and available with a single call of: **docker-compose up --build**.

#### Skills

-   Rigor
-   Group & interpersonal
-   Web

#### My grade

<img src="../img/score100.png" width="200" height="64"/>

## Getting started (Staging)

**Follow the steps below**

```bash
# Clone the project and access the folder
git clone https://github.com/mnweitenberg/codam.git && cd ft_transcendence/

# Register a new application in 42 intra
# create a .env file with your app info into the project root folder
# examples are given in .env.example

# Run make to build the imagesand run the containers
make

# Access the login page using the URL below
# Log in using your 42 account or one of the example accounts
http://localhost

# Run make clean to stop running containers
make clean

# Alert!
# This will clean up all your docker related files and containers
# Use this if you really want to clean your machine
make fclean

```

Made by:  
Justin Hille. [See my LinkedIn.](https://nl.linkedin.com/in/justin-hille/)  
Jonathan Bedaux. [See my LinkedIn.](https://www.linkedin.com/in/jonathan-bedaux-62629466/)  
Marius van Wijk. [See my LinkedIn.](https://nl.linkedin.com/in/marius-van-wijk-855a35170/)  
Milan Weitenberg. [See my LinkedIn.](https://www.linkedin.com/in/mnweitenberg/)
