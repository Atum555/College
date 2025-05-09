<?php

function output_head() { ?>
    <head>
        <title>Super Legit News</title>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <link rel="stylesheet" href="/styles/style.css" />
        <link rel="stylesheet" href="/styles/layout.css" />
        <link rel="stylesheet" href="/styles/comments.css" />
        <link rel="stylesheet" href="/styles/responsive.css" />
    </head>
<?php }

function output_header() { ?>
    <header>
        <h1><a href="/">Super Legit News</a></h1>
        <h2><a href="/">Where fake news are born!</a></h2>
        <div id="signup">
            <a href="/">Register</a>
            <a href="/">Login</a>
        </div>
    </header>
<?php }

function output_nav() { ?>
    <nav id="menu">
        <input type="checkbox" id="hamburger" />
        <label class="hamburger" for="hamburger"></label>

        <ul>
            <li><a href="/">Local</a></li>
            <li><a href="/">World</a></li>
            <li><a href="/">Politics</a></li>
            <li><a href="/">Sports</a></li>
            <li><a href="/">Science</a></li>
            <li><a href="/">Weather</a></li>
        </ul>
    </nav>
<?php }

function output_aside() { ?>
    <aside id="related">
        <article>
            <h1><a href="#">Duis arcu purus</a></h1>
            <p>
                Etiam mattis convallis orci eu malesuada. Donec odio ex, facilisis ac blandit vel, placerat ut
                lorem. Ut id sodales purus. Sed ut ex sit amet nisi ultricies malesuada. Phasellus magna diam,
                molestie nec quam a, suscipit finibus dui. Phasellus a.
            </p>
        </article>
        <article>
            <h1><a href="#">Sed efficitur interdum</a></h1>
            <p>
                Integer massa enim, porttitor vitae iaculis id, consequat a tellus. Aliquam sed nibh fringilla,
                pulvinar neque eu, varius erat. Nam id ornare nunc. Pellentesque varius ipsum vitae lacus ultricies,
                a dapibus turpis tristique. Sed vehicula tincidunt justo, vitae varius arcu.
            </p>
        </article>
        <article>
            <h1><a href="#">Vestibulum congue blandit</a></h1>
            <p>
                Proin lectus felis, fringilla nec magna ut, vestibulum volutpat elit. Suspendisse in quam sed tellus
                fringilla luctus quis non sem. Aenean varius molestie justo, nec tincidunt massa congue vel. Sed
                tincidunt interdum laoreet. Vivamus vel odio bibendum, tempus metus vel.
            </p>
        </article>
    </aside>
<?php }

function output_footer() { ?>
    <footer>
        <p>&copy; Fake News, 2022</p>
    </footer>
<?php }
