namespace scenes {
        void exec_dialogue(int x) {
        bool fals = false;
        int n = -1;

        switch (x) {
            case 0: {
                    Concepts::line lc[32] = {
                        {fals, true, 0, "BG: 1"},
                        {fals, true, 0, "S01:01"},
                        {fals, true, 0, ""},
                        {fals, true, 0, "                                 4:15 AM                          January 1st, 2000                                                 Providence of Nord Louisiane,    La République Laurentides"},
                        {fals, true, 0, "S01:02"},
                        {fals, true, 0, "                                 AHHHHG.                          I've been driving for hours.     My right foot's asleep, and the  left one isn't too far behind.   Where is it???"},        
                        {fals, true, 0, "S01:03"},
                        {fals, true, 0, "Look at that gumbo.              It has to be cold by now.                                         I can't believe they wanted me   to bring the food."},
                        {fals, true, 0, "S01:04"},
                        {fals, true, 0, "Y'know....                                                        If I don't see that castle in    fifteen minutes, I might just    head back."},
                        {fals, true, 0, "                                 At least the drive was nice,     I guess."},
                        {fals, true, 0, "S01:05"},
                        {fals, true, 0, "Okay, I give up. There's no way  that I'm gonna-"},
                        {fals, true, 0, "S01:06"},
                        {fals, true, 0, "                                                                  .....Oh."},
                        {fals, true, 0, "                                                                  I.. can't decide if I'm relieved or disappointed."},
                        {fals, true, 0, "BG: fadeout"},
                        {fals, true, 0, "S01:07"},
                        {fals, true, 0, "*Knock*                          *knock*                          *knock*"},
                        {fals, true, 0, "S01:08"},
                        {fals, true, 0, "                                                                  I wonder if they can even hear   me in there... This place looks  huge."},
                        {fals, true, 0, "                                                                                                                                    '.....coming!'"},
                        {fals, true, 0, "S01:09"},
                        {fals, true, 0, "BG: 0"},
                        {fals, true, 0, "                                                                  Hey, Maple!!                     C'mon in!"},
                        {fals, true, 0, "COM: Endscene"}
                    };

                    main::dialogue_page(lc);
                    break;
            }
            case 1: {
                Concepts::line lc[32] = {
                        {true, true, 0, "BG: Ocean"},
                        {true, fals, 1, "MAPLE                                                             Alright, so where do I plug this crock-pot in at? Are there any   plugs?"},
                        {fals, fals, 1, "MAPLE                                                             I take it that I'm late enough   y'all probably already ate       something else."},
                        {fals, true, 9, "ENOKI                                                             Well, we've got an outhouse,     but that's the only place with   electricity. And yeah, we got    some chicken."},
                        {fals, true, 8, "ENOKI                                                             We missed you earlier :("},
                        {fals, fals, 5, "MAPLE                                                             Well I'm finally here, now. So,  where is- Oh! Salut, Aaron."},
                       {true, true, 10, "AARON                                                             Bonsour! Or Bonjour more like, I guess, it's technically morning, isn't it? I'm just glad you got  here. Happy new millenium!"},
                        {fals, fals, 3, "MAPLE                                                             Happy new millenium! Y'all reallyare in the middle of nowhere, youknow that?"},
                       {true, true, 12, "DEL                                                               Maple! You're here! Happy 2000!"},
                        {fals, fals, 5, "MAPLE                                                             Delphine Thibodeaux!             My goodness it's been... what, a year? Salut!"},
                       {fals, true, 13, "DEL                                                               Hey, girl! Glad you're here -    Don't worry, we've been waiting  to break out the wine and        eclairs until you showed up."},
                       {fals, true, 12, "DEL                                                               We're all boring adults, though, so no promises about how late we would have stayed up for you."},
                        {true, true, 7, "ENOKI                                                             So Maple, what have you been up  to lately? Have we even talked   since the wedding?? I missed my  best friend :("},
                        {fals, fals, 2, "MAPLE                                                             Surely your husband's been       keeping you busy, I suppose."},
                       {true, true, 10, "AARON                                                             Well, we're obviously living in acastle now, so that's been an    adventure."},
                        {true, true, 7, "ENOKI                                                             I am a princess."},
                        {fals, fals, 2, "MAPLE                                                             It takes a little more than just a castle to be a princess."},
                        {fals, true, 8, "ENOKI                                                             I'm a duchess?"},
                        {fals, fals, 4, "MAPLE                                                             I- uhm...                        Hmm...                           You know what?                   It's too late for this."},
                        {fals, fals, 2, "MAPLE                                                             Anyway, I've been alright, I've  only got one semester left, then I'll be a school teacher.  Then? I don't know."},
                       {true, true, 10, "AARON                                                             Still trying this teacher thing, huh? Even though you've told me  a million times you'd rather be  anything but a teacher?"},
                       {fals, true, 11, "AARON                                                             Are there no degrees for people  who can shoot fire out of their  hands?"},
                        {fals, fals, 4, "MAPLE                                                             ...None I want, at least."},
                       {fals, true, 10, "AARON                                                             Well, a teacher with fire magic  sounds pretty cool to me."},
                        {true, true, 8, "ENOKI                                                             *yawn*                           Goodness, I'm sleepy. Hey, how   about we all go to bed and catch up in the morning?"},
                        {fals, true, 7, "ENOKI                                                             Hey Maple, you wanna have like   a sleepover? Like we can pretend we're college roommates again?"},
                        {fals, fals, 2, "MAPLE                                                             I mean... Sure, I guess."},
                        {fals, true, n, "ENOKI                                                             Goodnight, Del!                  Hey, Aaron, see ya tomorrow?     Bright 'n early?"},
                        {fals, true, 0, "AARON                                                             Sure thing, Noke-noke.                                            *kiss*"},
                        {fals, fals, 3, "MAPLE                                                             I am never going to get used to  that."},
                        {true, true, 9, "ENOKI                                                             Alright, grab your bag and I'll  show you where we're staying.    Allons-y!"},
                        {true, true, 0, "COM: Endscene"}
                    };
                    main::dialogue_page(lc);
                break;
            };
        }
    }
}