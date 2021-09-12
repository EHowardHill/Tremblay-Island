void exec_dialogue(int x) {
    bool fals = false;
    int n = -1;

    switch (x) {
        case 0: {
            Concepts::line lc[32] = {
                {fals, true, 0, "BG: 1"},
                {fals, true, 0, "S01:01"},
                {fals, true, 0, ""},
                {fals, true, 0, "4:15 AM                          January 1st, 2000                Providence of Nord Louisiane,    La République Laurentides"},
                {fals, true, 0, "S01:02"},
                {fals, true, 0, "                                 AHHHHG.                          I've been driving for hours.     My right foot's asleep, and the  left one isn't too far behind."},        
                {fals, true, 0, "S01:03"},
                {fals, true, 0, "                                 Look at that gumbo.              It has to be cold by now.        I can't believe they wanted me   to bring the food."},
                {fals, true, 0, "S01:04"},
                {fals, true, 0, "                                 Y'know....                       If I don't see that castle in    fifteen minutes, I might just    head back."},
                {fals, true, 0, "                                 At least the drive was nice,     I guess."},
                {fals, true, 0, "S01:05"},
                {fals, true, 0, "                                 Okay, I give up. There's no way  that I'm gonna-"},
                {fals, true, 0, "S01:06"},
                {fals, true, 0, "                                 .....Oh."},
                {fals, true, 0, "                                 I.. can't decide if I'm          relieved or disappointed."},
                {fals, true, 0, "BG: fadeout"},
                {fals, true, 0, "S01:07"},
                {fals, true, 0, "                                 *knock*                          *knock*                          *knock*"},
                {fals, true, 0, "S01:08"},
                {fals, true, 0, "                                 I wonder if they can even        hear me in there... This place   looks huge."},
                {fals, true, 0, "                                                                  '.....coming!'"},
                {fals, true, 0, "S01:09"},
                {fals, true, 0, "BG: 0"},
                {fals, true, 0, "                                                                  Hey, Maple!!                     C'mon in, allez!"},
                {fals, true, 0, "COM: Endscene"}
            };
            dialogue_page(lc);
            break;
        };

        case 1: {
            Concepts::line lc[32] = {
                {true, true, 0, "BG: Ocean"},
                {true, fals, 1, "MAPLE                            Alright, so where do I plug this crock-pot in at? Are there any   plugs?"},
                {fals, fals, 1, "MAPLE                            I take it that I'm late enough   y'all probably already ate       something else."},
                {fals, true, 9, "ENOKI                            Well, we've got an outhouse,     but that's the only place with   electricity. And yeah, we got    some chicken."},
                {fals, true, 8, "ENOKI                            We missed you earlier :("},
                {fals, fals, 5, "MAPLE                            Well I'm finally here, now. So,  where is- Oh! Salut, Aaron."},
                {true, true, 10, "AARON                            Bonsour! Or Bonjour more like, I guess, it's technically morning, isn't it? I'm just glad you got  here. Happy new millenium!"},
                {fals, fals, 3, "MAPLE                            Happy new millenium! Y'all reallyare in the middle of nowhere, youknow that?"},
                {true, true, 12, "DEL                              Maple! You're here! Happy 2000!"},
                {fals, fals, 5, "MAPLE                            Delphine Thibodeaux!             My goodness it's been... what, a year? Salut!"},
                {fals, true, 13, "DEL                              Hey, girl! Glad you're here -    Don't worry, we've been waiting  to break out the wine and        eclairs until you showed up."},
                {fals, true, 12, "DEL                              We're all boring adults, though, so no promises about how late we would have stayed up for you."},
                {true, true, 7, "ENOKI                            So Maple, what have you been up  to lately? Have we even talked   since the wedding?? I missed my  best friend :("},
                {fals, fals, 2, "MAPLE                            Surely your husband's been       keeping you busy, I suppose."},
                {true, true, 10, "AARON                            Well, we're obviously living in acastle now, so that's been an    adventure."},
                {true, true, 7, "ENOKI                            I am a princess."},
                {fals, fals, 2, "MAPLE                            It takes a little more than just a castle to be a princess."},
                {fals, true, 8, "ENOKI                            I'm a duchess?"},
                {fals, fals, 4, "MAPLE                            I- uhm...                        Hmm...                           You know what?                   It's too late for this."},
                {fals, fals, 2, "MAPLE                            Anyway, I've been alright, I've  only got one semester left, then I'll be a school teacher.  Then? I don't know."},
                {true, true, 10, "AARON                            Still trying this teacher thing, huh? Even though you've told me  a million times you'd rather be  anything but a teacher?"},
                {fals, true, 11, "AARON                            Are there no degrees for people  who can shoot fire out of their  hands?"},
                {fals, fals, 4, "MAPLE                            ...None I want, at least."},
                {fals, true, 10, "AARON                            Well, a teacher with fire magic  sounds pretty cool to me."},
                {true, true, 8, "ENOKI                            *yawn*                           Goodness, I'm sleepy. Hey, how   about we all go to bed and catch up in the morning?"},
                {fals, true, 7, "ENOKI                            Hey Maple, you wanna have like   a sleepover? Like we can pretend we're college roommates again?"},
                {fals, fals, 2, "MAPLE                            I mean... Sure, I guess."},
                {fals, true, n, "ENOKI                            Goodnight, Del!                  Hey, Aaron, see ya tomorrow?     Bright 'n early?"},
                {fals, true, 0, "AARON                            Sure thing, Noke-noke.                                            *kiss*"},
                {fals, fals, 3, "MAPLE                            I am never going to get used to  that."},
                {true, true, 9, "ENOKI                            Alright, grab your bag and I'll  show you where we're staying.    Allons-y!"},
                    {true, true, 0, "COM: Endscene"}
                };
            dialogue_page(lc);
            break;
        };

        case 2: {
            Concepts::line lc[32] = {
                {true, true, 0, "BG: fadeout"},
                {true, true, 0, "S01:11"},
                {true, true, 0, "MAPLE                            Wow.. It's sort of chilly in     here, isn't it?"},
                {true, true, 0, "ENOKI                            Well silly, why'd ya wear a tank top and shorts in the middle of  December? Can't ya just light a  fire?"},
                {true, true, 0, "BG: 2"},
                {true, true, 0, "S01:10"},
                {true, true, 0, "MAPLE                            So, how long are you two going tostay here? You can't just stay   thirty miles from civilization   without electricity forever."},
                {true, true, 0, "S01:11"},
                {true, true, 0, "ENOKI                            We're happy, so we think a long  time."},
                {true, true, 0, "MAPLE                            I mean, what does Aaron think of all this? The Aaron I remember   growing up would be a little more...responsible."},
                {true, true, 0, "ENOKI                            I don't wanna sound rude but...  Aren't you guys used to growing  up in places like, er, in a car?"},
                {true, true, 0, "MAPLE                            Enoki, we all know you're rich,  no need to flaunt it."},
                {true, true, 0, "ENOKI                            But didn't you literally grow up in a car? I mean, compared to    that, a castle is pretty nice,   right?"},
                {true, true, 0, "MAPLE                            It just seems.. rash. I don't    mean to take the fun out of it,  but I can't help but think this  was a really, really bad idea."},
                {true, true, 0, "ENOKI                            Coming from the girl who got     embarrased of her grades freshmanyear and decided to just up and  run away from college."},
                {true, true, 0, "S01:10"},
                {true, true, 0, "MAPLE                            Oh come on, that was your idea   first."},
                {true, true, 0, "S01:11"},
                {true, true, 0, "ENOKI                            Hey, I'll take it!! '97... Yeah, that was one of the best years   of my life, easy."},
                {true, true, 0, "ENOKI                            So, after college, you got any   plans for where you wanna live?"},
                {true, true, 0, "MAPLE                            I'll figure something out."},
                {true, true, 0, "ENOKI                            Aaron and I were chatting and,   y'know, there's a school not too far off you could teach at,      maybe you could.. y'know.."},
                {true, true, 0, "MAPLE                            Absolutely NOT. I'll make sure   to get myself a real adult       apartment."},
                {true, true, 0, "MAPLE                            When you get tired of this place,maybe you can move in with me."},
                {true, true, 0, "S01:12"},
                {true, true, 0, "ENOKI                            The kinda things you choose to befunny about Maple, it'll never   cease to amaze me."},
                {true, true, 0, "S01:11"},
                {true, true, 0, "ENOKI                            Hey- I'm feeling down and that's stupid! You wanna go on another  Maple and Enoki adventure like   old times??"},
                {true, true, 0, "ENOKI                            Let's go explore the castle!!"},
                {true, true, 0, "MAPLE                            Hold up, you bought this castle  and hadn't explored it all first?"},
                {true, true, 0, "ENOKI                            Well duh, I'm taking my sweet    time with it -- it's a castle!    Allons-y, let's explore!"},
                {true, true, 0, "COM: Endscene"}
            };
            dialogue_page(lc);
            break;
        };

        case 3: {
            Concepts::line lc[8] = {
                {true, true, 0, "                                                                  ENOKI                            Let's go for the room with-"},
                {true, true, 0, "                                                                  ENOKI                            -the big bookshelf!"},
                {true, true, 0, "                                                                  ENOKI                            There's gotta be secrets!"},
                {true, true, 0, "                                                                  ENOKI                            If you want me to lead,"},
                {true, true, 0, "                                                                  ENOKI                            just press 'B'."},
                {true, true, 0, "                                                                  MAPLE                            ...Huh?"},
                {true, true, 0, "                                                                  ENOKI                            What?"},
                {true, true, 0, "COM: Endscene"}
            };
            bn::sound_item hm = bn::sound_items::heymaple;
            hm.play();
            dialogue_page(lc);
            break;
        };

        case 4: {
            Concepts::line lc[5] = {
                {true, true, 0, "                                 You stare at the art."},
                {true, true, 0, "                                 And as such...."},
                {true, true, 0, "                                 So the art stares unto you."},
                {true, true, 0, "                                 Art is weird."},
                {true, true, 0, "COM: Endscene"}
            };
            dialogue_page(lc);
            break;
        };

        case 5: {
            Concepts::line lc[10] = {
                {true, true, 0, "                                                                  MAPLE                            Enoki, there's no window."},
                {true, true, 0, "                                                                  ENOKI                            Uh-huh?"},
                {true, true, 0, "                                                                  MAPLE                            What happens if someone tries-"},
                {true, true, 0, "                                                                  MAPLE                            to break in?"},
                {true, true, 0, "                                                                  ENOKI                            Aaron punches 'em."},
                {true, true, 0, "                                                                  ENOKI                            In the face."},
                {true, true, 0, "                                                                  MAPLE                            He's not here, though."},
                {true, true, 0, "                                                                  ENOKI                            Then I'll punch 'em."},
                {true, true, 0, "                                                                  MAPLE                            I.... Hmm. Alright, then."},
                {true, true, 0, "COM: Endscene"}
            };
            dialogue_page(lc);
            break;
        };

        case 6: {
            Concepts::line lc[10] = {
                {true, true, 0, "                                 You see a pot."},
                {true, true, 0, "                                 You feel compelled to smash it."},
                {true, true, 0, "                                 However, this is not possible."},
                {true, true, 0, "                                 You feel strangely disappointed."},
                {true, true, 0, "COM: Endscene"}
            };
            dialogue_page(lc);
            break;
        };

        case 7: {
            Concepts::line lc[19] = {
                {true, true, 0, "                                                                  MAPLE                            Hey, let's head out. I don't want"},
                {true, true, 0, "                                                                  MAPLE                            to wake him up."},
                {true, true, 0, "                                                                  ENOKI                            I dunno, it doesn't matter,"},
                {true, true, 0, "                                                                  ENOKI                            there's no way he'll wake up."},
                {true, true, 0, "                                                                  ENOKI                            He likes the light on, too."},
                {true, true, 0, "                                                                  MAPLE                            I thought you didn't have"},
                {true, true, 0, "                                                                  MAPLE                            electricity..?"},
                {true, true, 0, "                                                                  ENOKI                            Oh, we do- just that one plug."},
                {true, true, 0, "                                                                  ENOKI                            It's a very important plug."},
                {true, true, 0, "                                                                  MAPLE                            You sure you like this place?"},
                {true, true, 0, "                                                                  ENOKI                            You gonna come here and insult"},
                {true, true, 0, "                                                                  ENOKI                            my house?"},
                {true, true, 0, "                                                                  MAPLE                            Well, when you put it THAT way..."},
                {true, true, 0, "                                                                  ENOKI                            Uh huh, that's what I thought."},
                {true, true, 0, "                                                                  MAPLE                            Je m'excuse."},
                {true, true, 0, "                                                                  ENOKI                            Merci."},
                {true, true, 0, "                                                                  MAPLE                            But when you both move in with me"},
                {true, true, 0, "                                                                  MAPLE                            don't say I didn't warn y'all."},
                {true, true, 0, "COM: Endscene"}
            };
            dialogue_page(lc);
            break;
        };

        case 8: {
            Concepts::line lc[9] = {
                {true, true, 0, "                                                                  ENOKI                            Y'know, back when Del was my"},
                {true, true, 0, "                                                                  ENOKI                            nanny, my parents gave her like"},
                {true, true, 0, "                                                                  ENOKI                            three different rooms she could"},
                {true, true, 0, "                                                                  ENOKI                            stay in. I don't think she ever"},
                {true, true, 0, "                                                                  ENOKI                            slept anywhere but the tub."},
                {true, true, 0, "                                                                  MAPLE                            That actually sounds pretty nice."},
                {true, true, 0, "                                                                  ENOKI                            Yeah, I tried it but my skin"},
                {true, true, 0, "                                                                  ENOKI                            didn't like it very much."},
                {true, true, 0, "COM: Endscene"}
            };
            dialogue_page(lc);
            break;
        };

        case 9: {
            Concepts::line lc[9] = {
                {true, true, 0, "                                                                  MAPLE                            Enoki, this one's locked."},
                {true, true, 0, "                                                                  ENOKI                            Oh. Yeah, I think that's"},
                {true, true, 0, "                                                                  ENOKI                            the kitchen. We don't know where"},
                {true, true, 0, "                                                                  ENOKI                            the key is."},
                {true, true, 0, "                                                                  MAPLE                            So how do you eat??"},
                {true, true, 0, "                                                                  ENOKI                            We make most of our food over the"},
                {true, true, 0, "                                                                  ENOKI                            big fire pit!"},
                {true, true, 0, "                                                                  MAPLE                            You two, I *swear*...."},
                {true, true, 0, "COM: Endscene"}
            };
            dialogue_page(lc);
            break;
        };

        case 10: {
            Concepts::line lc[20] = {
                {true, true, 0, "                                                                  ENOKI                            Isn't he so cute when he"},
                {true, true, 0, "                                                                  ENOKI                            sleeps like that? <3"},
                {true, true, 0, "                                                                  MAPLE                            You've been married for, what,"},
                {true, true, 0, "                                                                  MAPLE                            a few months now?"},
                {true, true, 0, "                                                                  MAPLE                            Aren't you supposed to be at the"},
                {true, true, 0, "                                                                  MAPLE                            stage where neither of you talk"},
                {true, true, 0, "                                                                  MAPLE                            to each other at meals and both"},
                {true, true, 0, "                                                                  MAPLE                            of you've gained ten pounds?"},
                {true, true, 0, "                                                                  ENOKI                            Huh, I think I've lost weight."},
                {true, true, 0, "                                                                  MAPLE                            I guess I don't get it."},
                {true, true, 0, "                                                                  ENOKI                            Just cos you always get in"},
                {true, true, 0, "                                                                  ENOKI                            fights with your ex-boyfriends"},
                {true, true, 0, "                                                                  ENOKI                            doesn't mean every couple's like"},
                {true, true, 0, "                                                                  ENOKI                            that, tu sais."},
                {true, true, 0, "                                                                  ENOKI                            I mean, you've got this nasty"},
                {true, true, 0, "                                                                  ENOKI                            habit of-"},
                {true, true, 0, "                                                                  MAPLE                            You finish that sentence, and"},
                {true, true, 0, "                                                                  MAPLE                            I'll burn your eyebrows off."},
                {true, true, 0, "                                                                  ENOKI                            ......doing that."},
                {true, true, 0, "COM: Endscene"}
            };
            dialogue_page(lc);
            break;
        };

        case 11: {
            Concepts::line lc[32] = {
                {true, true, 0, "                                                                  ENOKI                            Nous sommes ici!"},
                {true, true, 0, "                                                                  ENOKI                            The bookshelf room."},
                {true, true, 0, "                                                                  MAPLE                            You weren't kidding about there"},
                {true, true, 0, "                                                                  MAPLE                            literally being just a bookshelf"},
                {true, true, 0, "                                                                  MAPLE                            room, were you?"},
                {true, true, 0, "                                                                  ENOKI                            Bon, so I can't move it and Aaron"},
                {true, true, 0, "                                                                  ENOKI                            can't either, so I was wondering,"},
                {true, true, 0, "                                                                  ENOKI                            how about using that elf magic?"},
                {true, true, 0, "                                                                  MAPLE                            Let me get this straight..."},
                {true, true, 0, "                                                                  MAPLE                            You want me to *burn* a perfectly"},
                {true, true, 0, "                                                                  MAPLE                            good bookshelf?"},
                {true, true, 0, "                                                                  ENOKI                            Yeah! I wanna see if there's a"},
                {true, true, 0, "                                                                  ENOKI                            secret passage behind it or"},
                {true, true, 0, "                                                                  ENOKI                            somethin', y'know?"},
                {true, true, 0, "                                                                  MAPLE                            I refuse. This is rediculous."},
                {true, true, 0, "                                                                  MAPLE                            These are perfectly good books."},
                {true, true, 0, "                                                                  ENOKI                            Most are rotting away, so"},
                {true, true, 0, "                                                                  ENOKI                            it's probably best that they get"},
                {true, true, 0, "                                                                  ENOKI                            burned. I checked."},
                {true, true, 0, "                                                                  MAPLE                            Are you sure?"},
                {true, true, 0, "                                                                  ENOKI                            Absolutely."},
                {true, true, 0, "                                                                  MAPLE                            Alright... I'll make a deal."},
                {true, true, 0, "                                                                  MAPLE                            I'll burn this, but you need to"},
                {true, true, 0, "                                                                  MAPLE                            save at least one book."}, //j'ai compris?
                {true, true, 0, "                                                                  MAPLE                            J'ai compris? Oui?"},
                {true, true, 0, "                                                                  ENOKI                            Oui!"},
                {true, true, 0, "                                                                  ENOKI                            ....alright, I got my book."},
                {true, true, 0, "                                                                  ENOKI                            Remember, use the 'R' trigger"},
                {true, true, 0, "                                                                  ENOKI                            to send out a bolt of fire!"},
                {true, true, 0, "                                                                  MAPLE                            ...What are you talking about??"},
                {true, true, 0, "                                                                  ENOKI                            Huh? Oh, nothing"},
                {true, true, 0, "COM: Endscene"}
            };
            dialogue_page(lc);
            break;
        };

        case 12: {
            Concepts::line lc[32] = {
                {true, true, 0, "                                                                  MAPLE                            ...."},
                {true, true, 0, "                                                                  ENOKI                            Well, there's no passage."},
                {true, true, 0, "                                                                  MAPLE                            You don't say."},
                {true, true, 0, "                                                                  ENOKI                            That's weird."},
                {true, true, 0, "                                                                  MAPLE                            Enoki... Look here."},
                {true, true, 0, "                                                                  MAPLE                            I guess it doesn't make any sense"},
                {true, true, 0, "                                                                  MAPLE                            to be angry, so I won't be, but.."},
                {true, true, 0, "                                                                  MAPLE                            You need to stop being like this."},
                {true, true, 0, "                                                                  MAPLE                            You and Aaron just spent all this"},
                {true, true, 0, "                                                                  MAPLE                            money on a barely furnished"},
                {true, true, 0, "                                                                  MAPLE                            castle without basic faculties"},
                {true, true, 0, "                                                                  MAPLE                            for what? So you could play like"},
                {true, true, 0, "                                                                  MAPLE                            you're a princess? While I'm over"},
                {true, true, 0, "                                                                  MAPLE                            in Carolina, sacrificing the best"},
                {true, true, 0, "                                                                  MAPLE                            parts of my life for an apartment"},
                {true, true, 0, "                                                                  MAPLE                            with the bare essentials?"},
                {true, true, 0, "                                                                  MAPLE                            Enoki... Please."},
                {true, true, 0, "                                                                  MAPLE                            I don't want to be the bad guy."},
                {true, true, 0, "                                                                  MAPLE                            I know you didn't really have a"},
                {true, true, 0, "                                                                  MAPLE                            childhood or parents, I get it."},
                {true, true, 0, "                                                                  MAPLE                            That's me too."},
                {true, true, 0, "                                                                  MAPLE                            But you can't keep going on like"},
                {true, true, 0, "                                                                  MAPLE                            this. Do you understand?"},
                {true, true, 0, "                                                                  ENOKI                            I do understand."}, //j'ai compris?
                {true, true, 0, "                                                                  MAPLE                            It's 5:00 in the morning, I'm"},
                {true, true, 0, "                                                                  MAPLE                            going back to bed. I'll see y'all"},
                {true, true, 0, "                                                                  MAPLE                            in the morning, oui?"},
                {true, true, 0, "                                                                  ENOKI                            Oui.."},
                {true, true, 0, "                                                                  MAPLE                            Hey, don't beat yourself up about"},
                {true, true, 0, "                                                                  MAPLE                            it. S'il te plait.. Bonne nuit."},
                {true, true, 0, "                                                                  ENOKI                            Bonne nuit.."},
                {true, true, 0, "COM: Endscene"}
            };
            dialogue_page(lc);
            break;
        };

        case 13: {
            Concepts::line lc[32] = {
                {true, true, 0, "S01:13"},
                {true, fals, 4, "..."},
                {true, true, 10, "AARON                            Bonjour! Did you sleep well?"},
                {fals, fals, 4, "MAPLE                            Yeah, it was ok I guess."},
                {true, true, 9, "ENOKI                            Bonjour! So.. We found something cool while you were sleeping, butyou've gotta promise you won't bemad."},
                {fals, fals, 4, "MAPLE                            You know I can't promise that."},
                {fals, true, 7, "ENOKI                            Remember that book you wanted me to get? Well, it's a world atlas!And we spotted something really  fun!"},
                {fals, true, 9, "ENOKI                            So, we found this island up in   Lake Supérieur called Tremblay  Island!"},
                {fals, fals, 0, "MAPLE                            Aw, that's fun. I was afraid thatthere'd be some kind of.. catch."},
                {fals, true, 0, "ENOKI                            Well, we, uh- figured it'd be funif, well, the idea came from Del,so..."},
                {true, true, 12, "DEL                              Last time we talked, my cousin   Rufus was obsessed with starting his own tiny country."},
                {true, true, 11, "AARON                            There's work not too far out, so if we need to pick up supplies,  it shouldn't be very difficult."},
                {true, true, 7, "ENOKI                            With the money we could make     selling off the castle, and with your magic, we were thinking-"},
                {fals, fals, 3, "MAPLE                            WHOA WHOA WHOA,                  JUST HOLD UP FOR A MINUTE."},
                {fals, fals, 3, "MAPLE                            Are you seriously telling me thatyou're going to SELL this castle and move to this random island,"},
                {fals, fals, 3, "MAPLE                            All because it shares the same   last name as us?"},
                {fals, true, 9, "ENOKI                            As a bonus, we're thinking we're gonna secede from the Laurentidesand be our own country, too."},
                {fals, fals, 0, "MAPLE                            ...I..."},
                {fals, fals, 0, "MAPLE                            ..."},
                {fals, fals, 4, "MAPLE                            ...I'm going to need some time toprocess this."},
                {true, true, 10, "AARON                            It sounds insane, but we've gone over the details, and it seems   like this could actually happen."},
                {true, true, 9, "ENOKI                            I know we had that talk last     night, but.."},
                {fals, fals, 3, "MAPLE                            And then what's next?            What happens after you get bored of being your own little island?"},
                {fals, fals, 0, "MAPLE                            Do you want to be the Pope? The  Queen of France? Are you going towant your own planet?"},
                {fals, fals, 0, "MAPLE                            And for what it's worth you're   lucky enough that you'll probablyget it. But you know what?"},
                {fals, fals, 0, "MAPLE                            I'm going to settle in reality   with my *real* job and stay out  of starving to death on some     rock,"},
                {fals, fals, 0, "MAPLE                            Or worse, getting locked up in   federal prison for breaking some sort of weird law."},
                {fals, fals, 4, "MAPLE                            Look.... It's been fun, but I    need to go home. I'm done with   this."},
                {fals, fals, 0, "MAPLE                            Aaron, Maple, Delphine, it's beenfun, but.... I need some time."},
                {true, true, 10, "AARON                            Are you sure? We can change the  subject, we were just talking.   We've got breakfast made if you  want some."},
                {fals, fals, 0, "MAPLE                            ..Alright, I'll stay a little    longer, but I do need to be      heading out soon."},
                {true, true, 0, "COM: Endscene"}
                };
            dialogue_page(lc);
            break;
        };

        case 14: {
            Concepts::line lc[32] = {
                {true, true, 0, "S02:02"},
                {true, true, 0, "BG: champ"},
                {true, true, 0, "                                                                                                   Hmm, hmm hmm hmm...."},
                {true, true, 0, "For goodness' sake, when is that pizza going to show up? Wasn't itsupposed to be here in under     twenty minutes?"},
                {true, true, 0, "                                 Have I checked my mail today? I  probably should go ahead and     check."},
                {true, true, 0, "S02:03"},
                {true, true, 0, "Huh, what's this? From the       Tremblay household? I guess I    haven't heard from Aaron and     Enoki in a while."},
                {true, true, 0, "                                                                  Can't wait to read about how muchthey want to move in with me now."},
                {true, true, 0, "BG: fadeout"},
                {true, true, 0, "S02:04"},
                {true, true, 0, "                                             Hey, Maple!"},
                {true, true, 0, "S02:05"},
                {true, true, 0, "Hold on, got this backwards."},
                {true, true, 0, "S02:04"},
                {true, true, 0, "BG: 0"},
                {true, true, 0, "                                             'Hey, Maple!'"},
                {true, true, 0, "      'We thought we'd send            you a quick letter to            give you an update.'"},
                {true, true, 0, "      'We sold the castle and          got to make enough to            buy a nice trailer home.'"},
                {true, true, 0, "      'However, that's not all-        we got it set up on our          new island!!'"},
                {true, true, 0, "S02:05"},
                {true, true, 0, "I'm...                           That's it,                       I'm gonna kill 'em."},
                {true, true, 0, "S02:04"},
                {true, true, 0, "      'So, we've decided that          we're going to name it-..'"},
                {true, true, 0, "COM: Endscene"}
            };
            dialogue_page(lc);
            break;
        };
    }
}