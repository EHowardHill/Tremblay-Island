int exec_dialogue(int x) {

    constexpr bool fals = false;
    constexpr int n = -1;

    switch (x) {
        case 0: {
            line lc[32] = {
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
                {fals, true, 0, "                                 Hey, Maple!!                     C'mon in, allez!"},
                {fals, true, 0, "COM: Endscene"}
            };
            dialogue_page(lc);
            return 0;
			break;
        };

        case 1: {
            bn::sound_items::maple_alright_03.play();
            line lc[32] = {
                {true, true, 0, "BG: Ocean"},
                {true, fals, 1, "MAPLE                            Alright, so where do I plug this crock-pot in at? Are there any   plugs?"},
                {fals, fals, 1, "MAPLE                            I take it that I'm late enough   y'all probably already ate       something else."},
                {fals, true, 9, "ENOKI                            Well, we've got an outhouse,     but that's the only place with   electricity. And yeah, we got    some chicken."},
                {fals, true, 8, "ENOKI                            We missed you earlier!"},
                {fals, fals, 5, "MAPLE                            Well I'm finally here, now. So,  where is- Oh! Salut, Aaron."},
                {true, true, 10, "AARON                            Bonsoir! Or Bonjour more like, I guess, it's technically morning, isn't it? I'm just glad you got  here. Happy new millenium!"},
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
            return 0;
			break;
        };

        case 2: {
            line lc[32] = {
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
                {true, true, 0, "ENOKI                            Well duh, I'm taking my sweet    time with it -- it's a castle!   Allons-y, let's explore!"},
                {true, true, 0, "COM: Endscene"}
            };
            dialogue_page(lc);
            return 0;
			break;
        };

        case 3: {
            line lc[32] = {
                {fals, fals, 00, "BG: Moody"},
                {true, true, 30, "ENOKI                                                             I wanna explore the big          bookshelf room first!"},
                {true, fals, 02, "MAPLE                                                             Sure, whatever."},
                {fals, true, 31, "ENOKI                                                             I think you're gonna see why     when we get there."},
                {fals, true, 30, "ENOKI                                                             If you want me to lead,          just press 'B'."},
                {fals, fals, 03, "MAPLE                                                             ...Huh?"},
                {fals, true, 30, "ENOKI                                                             What?"},
                {fals, fals, 00, "COM: Endscene"}};
            bn::sound_item hm = bn::sound_items::heymaple;
            hm.play();
            dialogue_page(lc);
            return 0;
            break;
        }

        case 13: {
            line lc[32] = {
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
                {fals, fals, 0, "MAPLE                            Aaron, Enoki, Delphine, it's beenfun, but.... I need some time."},
                {true, true, 10, "AARON                            Are you sure? We can change the  subject, we were just talking.   We've got breakfast made if you  want some."},
                {fals, fals, 0, "MAPLE                            ..Alright, I'll stay a little    longer, but I do need to be      heading out soon."},
                {true, true, 0, "COM: Endscene"}
                };
            dialogue_page(lc);
            return 0;
			break;
        };

        case 14: {
            line lc[32] = {
                {true, true, 0, "S02:02"},
                {true, true, 0, "BG: champ"},
                {true, true, 0, "                                 Hmm, hmm hmm hmm...."},
                {true, true, 0, "                                 For goodness' sake, when is that pizza going to show up? Wasn't itsupposed to be here in under     twenty minutes?"},
                {true, true, 0, "                                 Have I checked my mail today? I  probably should go ahead and     check."},
                {true, true, 0, "S02:03"},
                {true, true, 0, "                                 Huh, what's this? From the       Tremblay household? I guess I    haven't heard from Aaron and     Enoki in a while."},
                {true, true, 0, "                                 Can't wait to read about how muchthey want to move in with me now."},
                {true, true, 0, "BG: fadeout"},
                {true, true, 0, "S02:04"},
                {true, true, 0, "                                             Hey, Maple!"},
                {true, true, 0, "S02:05"},
                {true, true, 0, "                                 Hold on, got this backwards."},
                {true, true, 0, "S02:04"},
                {true, true, 0, "BG: 0"},
                {true, true, 0, "                                             'Hey, Maple!'"},
                {true, true, 0, "                                       'We thought we'd send            you a quick letter to            give you an update.'"},
                {true, true, 0, "                                       'We sold the castle and          got to make enough to            buy a nice trailer home.'"},
                {true, true, 0, "                                       'However, that's not all-        we got it set up on our          new island!!'"},
                {true, true, 0, "S02:05"},
                {true, true, 0, "                                 I'm...                           That's it,                       I'm gonna kill 'em."},
                {true, true, 0, "S02:04"},
                {true, true, 0, "                                       'So, we've decided that          we're going to name it-..'"},
                {true, true, 0, "COM: Endscene"}
            };
            dialogue_page(lc);
            return 0;
			break;
        };      

        case 15: {
            line lc[32] = {
                {true, true, 0, "S02:06"},
                {true, true, 0, "MAPLE                            Thunder my DOG,                  I have had ENOUGH,               they are ALL gonna get it!"},
                {true, true, 0, "MAPLE                            That's it! I'm at my limit.      They're going to DIE ALONE and   it's gonna be ALL their fault."},
                {true, true, 0, "MAPLE                            When they're tired of living thisisland fantasy, they're gonna    come here, and you know what I'llsay?"},
                {true, true, 0, "PIZZA GUY                        What will you say?"},
                {true, true, 0, "S02:07"},
                {true, true, 0, "MAPLE                            I'll say NO!"},
                {true, true, 0, "PIZZA GUY                        I dunno, living on an island by  yourself sounds kinda nice."},
                {true, true, 0, "MAPLE                            It's the nicest thing on the     planet, but they're gonna ruin itcos they're the most incompetant people on the planet!"},
                {true, true, 0, "PIZZA GUY                        If I were you, I'd go up and     teach 'em how to run the island."},
                {true, true, 0, "MAPLE                            I guess I'm gonna have to huh?   They're gonna die up there or    freeze to death!"},
                {true, true, 0, "MAPLE                            But I can't. I've gotta be the   better person and stay in adult  world."},
                {true, true, 0, "S02:06"},
                {true, true, 0, "PIZZA GUY                        Right, it's more important to    keep buying pizza and crying     yourself to sleep on your couch  like ya' do every night?"},
                {true, true, 0, "S02:08"},
                {true, true, 0, "MAPLE                            Is it really that obvious?"},
                {true, true, 0, "PIZZA GUY                        Yeah, we all take turns at the   place to see who'll get to       deliver to the 'sad pizza girl'."},
                {true, true, 0, "MAPLE                            Spectacular."},
                {true, true, 0, "S02:04"},
                {true, true, 0, "MAPLE                            Well, I suppose....              I mean, I don't exactly have the money to pay rent this month cos of all the pizza..."},
                {true, true, 0, "PIZZA GUY                        So... we gonna tip for today's   counseling session?"},
                {true, true, 0, "BG: fadeout"},
                {true, true, 0, "COM: Endscene"}
            };
            dialogue_page(lc);
            return 0;
            break;
        };

        case 16: {
            // Spring
            line lc[32] = {
                {fals, true, 0, "S03:01"},
                {fals, true, 0, "BG: 1"},
                {fals, true, 0, "6:40 PM                          March 20th, 2000                 The middle of Lake Supérieur,   La République Laurentides(?)"},
                {fals, true, 0, "                                 So.. That's the island.          It's cute."},
                {fals, true, 0, "                                 I'm not sure if it's sell-every- thing-I-own cute, but..."},
                {fals, true, 0, "                                 J'suppose the thought of living  on an island and having no debt  is pretty cool."},        
                {fals, true, 0, "S03:02"},
                {fals, true, 0, "MAPLE                            How much was the ferry again?    10 dollars?"},
                {fals, true, 0, "OLD SAILOR                       Aye lass, but aye've got one     warnin' fer ye befer ye dock."},
                {fals, true, 0, "MAPLE                            Oh dear, what?"},
                {fals, true, 0, "OLD SAILOR                       Keep yer wits about 'ye, ye neverknow who might go to stab ye."},
                {fals, true, 0, "MAPLE                            Will you take a 20?"},
                {fals, true, 0, "OLD SAILOR                       Aye, I can cut a 20."},
                {fals, true, 0, "COM: Endscene"}
            };
            dialogue_page(lc);
            return 0;
            break;
        }

        case 18: {
            line lc[32] = {
                {fals, fals, 0,  "BG: Trailer Home"},
                {true, true, 22, "ENOKI                            Maple!! You came!"},
                {true, fals, 17, "MAPLE                            Yeah, this was my best option."},
                {true, true, 24, "AARON                            How was the trip? Did it take youlong?"},
                {fals, fals, 16, "MAPLE                            I took the train. It was like..  three days? It was fine. I read alot. My legs hurt."},
                {fals, true, 25, "AARON                            If you'd had let us know you werecoming sooner, you know we would have arranged for a plane trip!"},
                {fals, fals, 18, "MAPLE                            Doesn't matter. I'm already here.So, you go from castle to mobile home? Classy."},
                {true, true, 20, "ENOKI                            Dude, we moved outta the castle  in a 'normal home' and now you   want us to go back?"},
                {fals, fals, 16, "MAPLE                            No, I mean.. I guess I don't     know what I mean."},
                {true, true, 26, "AARON                            Well, we've only got a couch, butit's very comfortable. Feel free to make yourself at home."},
                {fals, true, 24, "AARON                            We've been working hard. I've    been chopping wood for the winterand Enoki's been-"},
                {true, true, 22, "ENOKI                            So, I, uh, I thought bringing    some bunnies here would make the island a little more alive,      y'know?"},
                {fals, true, 20, "ENOKI                            Turns out they started           multiplying so I spenda lotta    time tryna' keep em out of the   garden."},
                {true, true, 26, "AARON                            How do you feel about going into the caves a little north of here?"},
                {fals, true, 24, "AARON                            We've heard there's some gems in there that could be really       useful in earning us some money."},
                {fals, fals, 14, "MAPLE                            I guess that isn't too difficult."},
                {fals, fals, 15, "MAPLE                            Hey... thanks for the room."},
                {fals, true, 25, "AARON                            No problem."},
                {fals, true, 22, "ENOKI                            Oh, and if you haven't met Scout yet, he's pretty cool! He's down in the bunker thing outside."},
                {fals, fals, 0, "COM: Endscene"}
            };
            dialogue_page(lc);
            return 0;
            break;
        }

        case 17: {
            line lc[32] = {
                {fals, fals, 0,  "BG: Trailer Home"},
                {true, true, 22, "ENOKI                            Well.. First day is done! I thinktoday was a lot of fun."},
                {true, fals, 17, "MAPLE                            You know what? I think I agree.  This is the most interesting day I've had in a while."},
                {true, true, 24, "AARON                            Ready to change your mind about  this having been a bad idea?"},
                {fals, fals, 16, "MAPLE                            I've only been here a day, I'll  give it some time before I make  my final judgement."},
                {fals, true, 25, "AARON                            Well, we're happy to have you.   I'm sorry, we only have a couch, but I'm working on a new home."},
                {fals, fals, 18, "MAPLE                            Oh, I slept on my couch back at  my old apartment all the time.   No need to worry."},
                {true, true, 20, "ENOKI                            Aw, you slept on a couch?"},
                {fals, fals, 16, "MAPLE                            It was a really nice couch."},
                {true, true, 26, "AARON                            Anyway, we're gonna get some     sleep. I've been chopping wood   all day and I'm tired."},
                {fals, true, 24, "AARON                            See you tomorrow?"},
                {true, true, 22, "ENOKI                            I'm sure I'll find more stuff to do!"},
                {fals, fals, 15, "MAPLE                            Thanks again. I'll do my best to not be a butt about all this.    Goodnight, y'all."},
                {fals, true, 22, "ENOKI                            Bonne nuit!"},
                {fals, fals, 0, "COM: Endscene"}
            };
            dialogue_page(lc);
            return 0;
            break;
        }

        case 19: {
            line lc[32] = {
                {fals, fals, 0,  "BG: fadeout"},
                {fals, fals, 0,  "S04:01"},
                {fals, fals, 0,  "                                 Ugh.. My head.                   Why can't I sleep?"},
                {fals, fals, 0,  "                                 Aren't you supposed to be able tosleep easier after a long day of travel and manual labor?"},
                {fals, fals, 0,  "                                 And where's that light coming    from outside? Probably Scout or  something."},
                {fals, fals, 0,  "                                 Maybe I should go on a walk and  check it out."},
                {fals, fals, 0,  "S04:02"},
                {fals, fals, 0,  "                                 What the-                        is that a Mons d'Plonj? Is he    writing something?"},
                {fals, fals, 0,  "                                 I guess I should go check it out.Before something bad happens."},
                {fals, fals, 0,  "S04:03"},
                {fals, fals, 0,  "                                 Hmmm, hmmm... hmmm...."},
                {fals, fals, 0,  "S04:04"},
                {fals, fals, 0,  "MAPLE                            HEY! IDENTIFY YOURSELF, OR I'LL  BURN YOUR FACE OFF!"},
                {fals, fals, 0,  "S04:05"},
                {fals, fals, 0,  "SF: Rufus Squeak"},
                {fals, fals, 0,  "                                 AHHHH?!"},
                {fals, fals, 0,  "                                 AH, UH.. UH, RUFUS!              RUFUS THIBODEAUX!"},
                {fals, fals, 0,  "                                 DON'T BURN MY FACE OFF, I NEED   THAT!"},
                {fals, fals, 0, "COM: Endscene"}
            };
            dialogue_page(lc);
            return 0;
            break;
        }

        case 20: {
            line lc[32] = {
                {fals, fals, 0,  "BG: frog"},
                {fals, fals, 0,  "S04:06"},
                {fals, fals, 0,  "MAPLE                            Oh, so you're /that/ Rufus? Del'scousin, right? I'm Maple."},
                {fals, fals, 0,  "RUFUS                            Oh, you're the fire elf, right?  Wish I knew that earlier when I  was trying to get this fire      started."},
                {fals, fals, 0,  "MAPLE                            What are you doing here?"},
                {fals, fals, 0,  "RUFUS                            Just checking things out. I've   got my eye on the Bill & Jim     Islands next door."},
                {fals, fals, 0,  "RUFUS                            I really like the idea of just   having my own place and not      having to talk to anyone."},
                {fals, fals, 0,  "RUFUS                            I'm just worried this whole      'private island' thing is...     kind of foolhardy."},
                {fals, fals, 0,  "RUFUS                            Everyone this close to Quebec    speaks with that annoying accent,too."},
                {fals, fals, 0,  "MAPLE                            That's what I was afraid of, too.Enoki is great, but that accent  wears on me sometimes."},
                {fals, fals, 0,  "MAPLE                            I'm starting to hear a little    Quebec in Aaron's voice, too.    It bothers me."},
                {fals, fals, 0,  "MAPLE                            So what are you writing?"},
                {fals, fals, 0,  "RUFUS                            ...                              You're going to think it's       dumb. It's a drawing."},
                {fals, fals, 0,  "MAPLE                            Look, I just sold everything I   owned to move to this stupid     island, your drawing isn't dumb."},  
                {fals, fals, 0,  "RUFUS                            ...Okay, it's a frog. I saw this picture of a frog when I was a   kid, and I don't know why, but itmakes me nostalgic."},
                {fals, fals, 0,  "RUFUS                            I can't quite remember what it   looked like though, so I keep    trying. I don't know why but it'ssomething I just have to do."},  
                {fals, fals, 0,  "MAPLE                            Yeah, that is pretty dumb, but   I think I get what you mean."},
                {fals, fals, 0,  "MAPLE                            Hey, I know it's not my place to offer, but you got a place to    sleep? I know it's cold out, but we have a bathtub."},
                {fals, fals, 0,  "RUFUS                            Oh it's fine, I'll be gone in themorning, I don't really want to  interact with anyone else. You   seem reasonable, though."},
                {fals, fals, 0,  "MAPLE                            You too. It was kind of nice to  find someone with any sense to   chat for a little while."},
                {fals, fals, 0,  "S04:07"},
                {fals, fals, 0,  "BG: fadeout"},
                {fals, fals, 0,  "MAPLE                            You take care of yourself,       alright? Ravi de vous rencontrer,Rufus."},
                {fals, fals, 0,  "RUFUS                            You too! Ravi de vous rencontrer,Maple."},
                {fals, fals, 0, "COM: Endscene"}
            };
            dialogue_page(lc);
            return 0;
            break;
        }

        case 21: {
            line lc[32] = {
                {fals, fals, 0,  "BG: news"},
                {fals, fals, 0,  "S_STV_01"},
                {fals, fals, 0,  "                                 Hey, y'all! Scout here.                                           It's that time again!"},
                {fals, fals, 0,  "S_STV_02"},
                {fals, fals, 0,  "                                 It's exciting to finally have a  real audience, ladies and        gentlemen. Er.. gentleman."},
                {fals, fals, 0,  "                                 It's April 1st, and you know     what that means!"},
                {fals, fals, 0,  "                                 We've had Maple Tremblay come    move into the island for a whole day, now! Time flies, man."},
                {fals, fals, 0,  "                                 That's a, uh, joke..             Cuz it's April 1st, she's been   here a month now.."},
                {fals, fals, 0,  "                                 I'll just, uh, move on.. So..    ..Right! So I finally found out  my computer password!            That's good."},
                {fals, fals, 0,  "                                 Oh, right- Right, the most       important bit. We have three new people moving into the village!"},
                {fals, fals, 0,  "                                 I'm not sure we'll be able to    find any new potential islanders from Craigslist, though."},
                {fals, fals, 0,  "                                 They're named Diana, Eleanor, andOlivier, and they're moving into the new cabin to the northwest."},
                {fals, fals, 0,  "                                 Olivier has a greenhose up north,and Diana is actually an aspiringsailor! She'll be taking over    boat piloting."},
                {fals, fals, 0,  "                                 So just make sure to give them a warm welcome."},
                {fals, fals, 0,  "S_STV_01"},
                {fals, fals, 0,  "                                 Alright, that's all..            I suppose I'll see y'all later   today. Thanks for tuning in!"},
                {fals, fals, 0,  "S05:01"},  
                {fals, fals, 0,  "BG: fadeout"},
                {fals, fals, 0,  "ENOKI                            Mmmmmm....                       I made popcorn, but I don't wannaget up to get it out of the      microwave."},
                {fals, fals, 0,  "SF: Hey Maple"},
                {fals, fals, 0,  "ENOKI                            Could you get it, Maple?         S'il te plait?"},
                {fals, fals, 0,  "MAPLE                            Ugh, get a room already, you two."},
                {fals, fals, 0,  "AARON                            Maple, this is our house."},
                {fals, fals, 0,  "MAPLE                            Whatever."},
                {fals, fals, 0, "COM: Endscene"}
            };
            dialogue_page(lc);
            return 0;
            break;
        }

        case 22: {
            line lc[32] = {
                {fals, fals, 0, "                                                                  APRIL 1st, 2000 -                Scout log No. 48"},
                {fals, fals, 0, "                                                                  Scout TV broadcast actually had  a few viewers this time. I hope  they liked it."},
                {fals, fals, 0, "                                                                  Maybe next time I'll finally haveenough people that I can host my very first Scout Expo."},
                {fals, fals, 0, "                                                                  This dirt stuff is going really  slowly, and I've got funding, so"},
                {fals, fals, 0, "                                                                  I'm happy that I'm able to work  on stuff for fun."},
                {fals, fals, 0, "                                                                  The 'bag of holding' isn't going to be done fora while, but the"},
                {fals, fals, 0, "                                                                  prototype shows lots of promise."},
                {fals, fals, 0, "                                                                  Maybe it could work for that     request Aaron gave me when he"},
                {fals, fals, 0, "                                                                  wanted a way to race cars on the island."},
                {fals, fals, 0, "                                                                  I could just stick a whole       racetrack in the pocket dimension"},
                {fals, fals, 0, "                                                                  so we don't have to tear the     whole place up."},
                {fals, fals, 0, "                                                                  Of course, it has to be perfect. If he gets stuck there..."},
                {fals, fals, 0, "                                                                  Yeah, it's gotta be perfect."},
                {fals, fals, 0, "COM: Endscene"}
            };
            dialogue_page_lite(lc);
            return 0;
            break;
        }

        case 23: {
            line lc[32] = {
                {fals, fals, 0, "                                                                  MARCH 29th, 2000 -               Scout log No. 45 (deleted)"},
                {fals, fals, 0, "                                                                  Gotta be the best day since I    moved over here from the Bill &"},
                {fals, fals, 0, "                                                                  Jim islands. I do NOT miss those islands."},
                {fals, fals, 0, "                                                                  That Rufus guy was a real pain inthe patookas. Constantly"},
                {fals, fals, 0, "                                                                  yammering on about that          conspiracy stuff"},
                {fals, fals, 0, "                                                                  I hope he's doing fine by himselfover there."},
                {fals, fals, 0, "                                                                  But man, that Maple girl... whew.I think she smiled at me for the"},
                {fals, fals, 0, "                                                                  first time since she came here."},
                {fals, fals, 0, "                                                                  It probably doesn't mean anythingbut I haven't been able to sleep"},
                {fals, fals, 0, "                                                                  just thinking about it."},
                {fals, fals, 0, "                                                                  She hasn't ever said anything to me that wasn't making fun of me"},
                {fals, fals, 0, "                                                                  but maybe she's just playing hardto get."},
                {fals, fals, 0, "                                                                  I've seen how she talks to Aaron and Enoki, she's like that to    everyone."},
                {fals, fals, 0, "                                                                  Mmm.. Maybe someday I'll figure  out how to talk to her. Maybe"},
                {fals, fals, 0, "                                                                  I'll make somethingt that really impresses her."},
                {fals, fals, 0, "                                                                  She's never acts like she's      interested in anything but she   likes food and books."},
                {fals, fals, 0, "                                                                  Maybe it's not the same kinds,   but I like food and books too."},
                {fals, fals, 0, "                                                                  Maybe she just likes bigger guys though, and I'm shaped like      Grimace from McDonald's."},
                {fals, fals, 0, "                                                                  That's it. I'll invent a way to  get me into shape."},
                {fals, fals, 0, "                                                                  But she SMILED at me.            Now, it was because I tripped on"},
                {fals, fals, 0, "                                                                  something, but maybe she thinks  I'm cute."},
                {fals, fals, 0, "                                                                  I've gotta delete this log when  I'm done writing it."},
                {fals, fals, 0, "COM: Endscene"}
            };
            dialogue_page_lite(lc);
            return 0;
            break;
        }

        case 24: {
            line lc[32] = {
                {fals, fals, 0, "                                                                  MARCH 30th, 2000 -               Scout log No. 46 (deleted)"},
                {fals, fals, 0, "                                                                  That Rufus guy was a real pain inthe patookas. Constantly"},
                {fals, fals, 0, "                                                                  yammering on about that          conspiracy stuff"},
                {fals, fals, 0, "                                                                  Those folks from the company sentme a real cryptic message today."},
                {fals, fals, 0, "                                                                  Apparently they're not interestedin 'results' anymore, they just"},
                {fals, fals, 0, "                                                                  want me to install more surveillance equipment."},
                {fals, fals, 0, "                                                                  Is it official? Maybe they want  Scout TV to be a real broadcast?"},
                {fals, fals, 0, "                                                                  I'm suspicious it's gotta do withthat Rufus guy."},
                {fals, fals, 0, "                                                                  They keep asking me about him,   even though we don't work        together."},
                {fals, fals, 0, "                                                                  It's like they wanna arrest him, but they're waiting for whatever he's inventing to be done, first."},
                {fals, fals, 0, "                                                                  It wouldn't surprise me."},
                {fals, fals, 0, "                                                                  Yeah, this log can't be left on  my PC."},
                {fals, fals, 0, "COM: Endscene"}
            };
            dialogue_page_lite(lc);
            return 0;
            break;
        }

        case 25: {
            line lc[32] = {
                {fals, fals, 0, "                                                                  TIME RAIDERS: GENESIS            a fan creation by                ICHABOD 'SCOUT' WILLIAMS"},
                {fals, fals, 0, "                                                                  The time for reckoning was upon  him, Jahn-Jahn Gazebo felt. It   was only a matter of time before"},
                {fals, fals, 0, "                                                                  Star Space Goblin Emperor Wizard would catch up to his planet. Butthe Time Raiders   were prepared."},
                {fals, fals, 0, "                                                                  The squeebo-zeebos had warned himahead of time, so he and his bandwere ready."},
                {fals, fals, 0, "                                                                  They were going to hide in plain sight by pretending to be a      different band - 'Space Raiders'."},
                {fals, fals, 0, "                                                                  Jahn-Jahn had given his guitar   sword a new paint job."},
                {fals, fals, 0, "                                                                  Nexus, his quipster sidekick, hadfashioned his keyboard to look"},
                {fals, fals, 0, "                                                                  like a computer keyboard, and    swapped out his Mondo Glasses    for a pair of normal sunglasses."},
                {fals, fals, 0, "                                                                  Ninjette, their drummer and      ninja, had disguised her mondo"},
                {fals, fals, 0, "                                                                  nunchucks / drumsticks as a pair of chicken drumsticks. They      looked very delicious."},
                {fals, fals, 0, "                                                                  The time had come. They decided  to swap genres. Country music waswhat they were going with."},
                {fals, fals, 0, "                                                                  Soon enough, the Star Space      Goblin Emperor Wizard had landed on Sqeeb-Sqeeb 9."},
                {fals, fals, 0, "                                                                  'AAALRIGHT!' he exclaimed, 'I AM SEARCHING FOR JAHN-JANH GAZEBO!"},
                {fals, fals, 0, "                                                                  HIS SKULL WILL MEET MY WICKED    FIST OF EVIL!.. FOR EVIL!'"},
                {fals, fals, 0, "                                                                  'Not so fast, Star Space Goblin  Emperor Wizard!' said Jahn-Jahn, wearing a fake wig."},
                {fals, fals, 0, "                                                                  'How do you know, random         civilian?' asked the Star Space"},
                {fals, fals, 0, "                                                                  Goblin Emperor Wizard, who did   not recognize his nemesis."},
                {fals, fals, 0, "                                                                  'I wrote a song about it! Wanna  hear it? Here it goes!' And withthat, the song began."},
                {fals, fals, 0, "                                                                  Because it was country music, it sucked so hard that all of his  goons died."},
                {fals, fals, 0, "                                                                  The Star Space Goblin Emperor    Wizard himself was suspicious"},
                {fals, fals, 0, "                                                                  that it was actually them, but   Ninjette thought fast."},
                {fals, fals, 0, "                                                                  She tossed one of the chicken    legs into his mouth, which he"},
                {fals, fals, 0, "                                                                  thought was delicious. It bought them enough time to leave."},
                {fals, fals, 0, "                                                                  That's when they met a dude namedScout, who was a fantasitc pilotwho helped them escape."},
                {fals, fals, 0, "                                                                  'Wow, Scout! You're such a great pilot!' said Jahn-Jahn. 'Do you  want to join the Time Raiders?'"},
                {fals, fals, 0, "                                                                  Scout immediately accepted, and  everyone lived happily ever      after."},
                {fals, fals, 0, "                                                                  I can't believe this story got   rejected from the Time Raiders   script competition, it's perfect."},
                {fals, fals, 0, "COM: Endscene"}
            };
            dialogue_page_lite(lc);
            return 0;
            break;
        }

        case 26: {
            line lc[32] = {
                {fals, fals, 0, "                                                                  Huh... I never thought I'd       actually beat the game."},
                {fals, fals, 0, "                                                                  Maybe I should do something aboutit."},
                {fals, fals, 0, "                                                                  Eh, later."},
                {fals, fals, 0, "COM: Endscene"}
            };
            dialogue_page_lite(lc);
            return 0;
            break;
        }

        case 27: {
            line lc[32] = {
                {fals, fals, 0, "S_DOCKS"},
                {true, true, 28, "CAP'N NICHOLAS                                                    Ahoy there, lass! Are ye ready   fer yer a voyage?"},
                {true, fals, 29, "DIANA                                                             Aye aye, Captain!"},
                {fals, true, 28, "CAP'N NICHOLAS                                                    Just remember what I told ye' -  watch out fer the rocks, and     watch yer speed!"},
                {fals, fals, 29, "DIANA                                                             Aye aye, sir!"},
                {fals, fals, 0, "COM: Endscene"}
            };
            dialogue_page(lc);
            return 0;
            break;
        }

        case 28: {
            line lc[32] = {
                {fals, fals, 0,  "BG: news"},
                {fals, fals, 0,  "S_STV_01"},
                {fals, fals, 0,  "                                 Hey, y'all! Scout here.                                           It's that time again!"},
                {fals, fals, 0,  "S_STV_02"},
                {fals, fals, 0,  "                                 Scout TV is a regular thing goingon! Check it out, I feel like a  real reporter now!"},
                {fals, fals, 0,  "                                 We've all been on this island forthree good months, now. I can't  decide if it feels more like a   day or a million years long."},
                {fals, fals, 0,  "                                 Well, it's taken a while, but it looks like we're getting two new islanders!"},
                {fals, fals, 0,  "                                 We've got a certain Cesar de la  Cruz on special invitation from  our very own Queen Enoki."},
                {fals, fals, 0,  "                                 He was apparently a famous lawyerwho's decided that he wants a newstart."},
                {fals, fals, 0,  "                                 We've also got a guy moving in   whose name is.. Guy. I'm not     kidding - his name is Guy."},
                {fals, fals, 0,  "                                 I'm looking forward to seeing    what he cooks up, literally! He'sa cook and apparently makes a    mean jumbalaya."},
                {fals, fals, 0,  "                                 Now, we're getting ever closer tothe Scout Expo, and it's only a  matter of time before it's all   ready."},
                {fals, fals, 0,  "                                 I've also managed to order a     bunch of new Time Raiders comic, cuz I know a bunch of islanders  have really been getting into-"},
                {fals, fals, 0,  "BG: fadeout"},
                {fals, fals, 0,  "S_STV_03"},  
                {fals, fals, 0,  "                                 . . . ."},
                {fals, fals, 0,  "BG: rain"},
                {fals, fals, 0,  "S_STV_04"},
                {fals, fals, 0,  "                                 I, er- hmm.. Yes, good evening,  island neighbors. It is I, Rufus Thibodeaux, and if you do not    know me, you soon will."},
                {fals, fals, 0,  "                                 I have interrupted this broadcastto let you know that I am giving you an ultimatum. Either you     submit your island to me, or-!"},
                {fals, fals, 0,  "BG: fadeout"},
                {fals, fals, 0,  "S_STV_03"},  
                {fals, fals, 0,  "                                 . . . ."},
                {fals, fals, 0,  "S_STV_01"},
                {fals, fals, 0,  "                                 -and that's all, folks! See y'allnext time!"},
                {fals, fals, 0,  "S05:02"},
                {fals, fals, 0,  "ENOKI                            Aw, I missed the end of the Scoutbroadcast. I was looking forward to it."},
                {fals, fals, 0,  "MAPLE                            Hey, isn't that twerp Del's      nephew? He, uh, stopped by the   island a few months ago, I think."},
                {fals, fals, 0,  "AARON                            What a strange broadcast."},
                {fals, fals, 0,  "ENOKI                            I'm gonna get a soda."},
                {fals, fals, 0,  "COM: Endscene"}
            };
            dialogue_page(lc);
            return 0;
            break;
        }

        case 29: {
            line lc[32] = {
                {fals, fals, 0,  "BG: fadeout"},
                {fals, fals, 0,  ". . ."},
                {fals, fals, 0,  "BG: 1"},
                {fals, fals, 0,  "ENOKI                            Hey, Aaron?"},
                {fals, fals, 0,  "AARON                            *yawn* Yeah?"},
                {fals, fals, 0,  "ENOKI                            Are you happy?"},
                {fals, fals, 0,  "AARON                            Of course I am, Noke."},
                {fals, fals, 0,  "ENOKI                            No, I mean.. Are you really,     actually happy?                  I worry about you."},
                {fals, fals, 0,  "AARON                            I guess I'm just a little        melancholy about it, that's all."},
                {fals, fals, 0,  "ENOKI                            What d'you mean?"},
                {fals, fals, 0,  "AARON                            I think you know. Maple is right,we're only able to be here       because of that money you won."},
                {fals, fals, 0,  "AARON                            We gambled it all, so if anythinghappens to this place, we've got absolutely nothing."},
                {fals, fals, 0,  "ENOKI                            You know me though, I'm lucky,   we'll be okay. And besides, I gotyou! That's enough."},
                {fals, fals, 0,  "AARON                            You might not feel like that whenyou're hungry. You don't know    what it's like to be hungry."},
                {fals, fals, 0,  "ENOKI                            I don't wanna think about this.. it'll keep me up."},
                {fals, fals, 0,  "ENOKI                            Can we just be happy now and talkabout these things later?"},  
                {fals, fals, 0,  "AARON                            I guess so. Goodnight, Noke."},
                {fals, fals, 0,  "ENOKI                            Goodnight, Aire."},
                {fals, fals, 0,  "BG: fadeout"},
                {fals, fals, 0,  ". . ."},
                {fals, fals, 0,  "COM: Endscene"}
            };
            dialogue_page(lc);
            return 0;
            break;
        }

        case 30: {
                line lc[32] = {
                    {fals, fals, 0,  "BG: CRUZ01"},
                    {fals, fals, 0,  "                                 Oh! Hey, nice to meet you!       You must be one of the locals.   You can call me Cesar."},
                    {fals, fals, 0,  "                                 Believe it or not, I used to be  a lawyer, you know. I wasn't a   very good one, though."},
                    {fals, fals, 0,  "BG: CRUZ02"},
                    {fals, fals, 0,  "                                 Then again, I didn't even have a degree and there I was, winning  court cases one after the other."},
                    {fals, fals, 0,  "                                 So why am I telling you all this,despite never having seen you    before?"},
                    {fals, fals, 0,  "                                 ..."},
                    {fals, fals, 0,  "BG: CRUZ01"},
                    {fals, fals, 0,  "                                 ..."},
                    {fals, fals, 0,  "                                 Just in case we need to keep our narratives straight, oui?"},
                    {fals, fals, 0,  "                                 But that's neither here nor      there. I'm fulfilling my dream ofbeing a quiet shopkeep."},
                    {fals, fals, 0,  "                                 If any angry former clients of   mine decide to stop by, just let me know so I can.. er.. hide.    Merci!"},
                    {fals, fals, 0,  "                                 Anyway, what might I interest youin today?"},
                    {fals, fals, 0,  "COM: Endscene"}
                };
            dialogue_page(lc);
            return 0;
            break;
        }

        case 31: {
                line lc[32] = {
                    {fals, fals, 0,  "BG: CRUZ01"},
                    {fals, fals, 0,  "                                 Enoki Ramirez! Er... Tremblay nowis it? Anyway, thank you so much for letting me come here."},
                    {fals, fals, 0,  "                                 I promise I won't cause any      trouble, but those last clients  of mine..."},
                    {fals, fals, 0,  "BG: CRUZ02"},
                    {fals, fals, 0,  "                                 Look, it's not MY fault that I   was able to pretend to be a      lawyer really well, you know?"},
                    {fals, fals, 0,  "BG: CRUZ01"},
                    {fals, fals, 0,  "                                 I know you understand. Just let  me know if they arrive so I can, you know, er.. hide."},
                    {fals, fals, 0,  "                                 It's been a childhood dream of   mine to be a shopkeep in some    little village, and I don't have a lot to sell,"},
                    {fals, fals, 0,  "                                 But I'll do my best! Anyway, how can I help you today?"},
                    {fals, fals, 0,  "COM: Endscene"}
                };
            dialogue_page(lc);
            return 0;
            break;
        }
        
        case 32: {
            line lc[32] = {
                {fals, fals, 0,  "S_STV_03"},  
                {fals, fals, 0,  "                                 . . . ."},
                {fals, fals, 0,  "BG: rain"},
                {fals, fals, 0,  "S_STV_04"},
                {true, true, 00, "RUFUS                            Good evening, everyone.          It seems as if my warning was    not enough for you, as no one   "},
                {true, true, 00, "RUFUS                            has shown even the tiniest hint  of fear over the past month.     This is a dreadful mistake,      for you see, I have concocted a "},
                {true, true, 00, "RUFUS                            plan to overwhelm your defenses  and take your island for         myself."},
                {fals, fals, 00, "S06:01"},
                {true, true, 00, "MAPLE                            ...Ugggh, shut up, Rufus, I'm    trying to sleep."},
                {true, true, 00, "RUFUS                            I have developed a-"},
                {fals, fals, 00, "S06:02"},
                {true, true, 00, "ENOKI                            I don't remember turning the     TV on this morning, you do       that, Maple?"},
                {true, true, 00, "MAPLE                            ..."},
                {fals, fals, 00, "S06:03"},
                {true, true, 00, "AARON                            Maybe I accidentally pushed      something. Should I turn it      off?"},
                {true, true, 00, "MAPLE                            ...mmmrff... tv... turn          off... saturday..."},
                {true, true, 00, "RUFUS                            In exactly T-Minus thirty        seconds, I will unleash my-"},
                {fals, fals, 0,  "BG: fadeout"},
                {true, true, 00, "AARON                            Okay, it's off now."},
                {true, true, 00, "ENOKI                            What's he always on about?"},
                {true, true, 00, "AARON                            I don't know, Noke."},
                {true, true, 00, "MAPLE                            ..."},
                {fals, fals, 00, "SF: Boom"},
                {true, true, 00, "ENOKI                            Hey, what's that noise?"},
                {true, true, 00, "AARON                            I don't like that, it sounds     like... Hey, Maple, maybe you    should get up."},
                {true, true, 00, "MAPLE                            ...grr, I'm gonna kill that      gator..."},
                {true, true, 00, "ENOKI                            What the- oh no.."},
                {true, true, 00, "AARON                            Enoki, you and Maple go to       Scout's bunker, I'm going to     check on everyone out west."},
                {true, true, 00, "MAPLE                            Excusez-moi, I can take care     of-"},
                {true, true, 00, "AARON                            You go to the bunker and get     some more sleep."},
                {true, true, 00, "MAPLE                            Hey, no need to be               passive-aggressive about it."},
                {fals, fals, 0,  "COM: Endscene"}
            };
        dialogue_page(lc);
        return 0;
        }

        case 33: {
            line lc[32] = {
                {fals, fals, 0,  "S07:01"},  
                {fals, fals, 0,  "BG: fadeout"},
                {true, true, 00, "MAPLE                            So come clean with me, oui?      Did you make this place?"},
                {true, true, 00, "SCOUT                            Heck no! I kind of wish I did,   though."},
                {true, true, 00, "S07:02"},
                {true, true, 00, "..."},
                {true, true, 00, "S07:03"},
                {true, true, 00, "SCOUT                            MAPLE LOOK OUT!"},
                {true, true, 00, "S07:04"},
                {true, true, 00, "MAPLE                            ...Scout, are you alright?"},
                {true, true, 00, "RUFUS                            Ow. I think it popped my back a  bit, though."},
                {true, true, 00, "S07:05"},
                {true, true, 00, "MAPLE                            What's with all the gasoline in  this place, huh?"},
                {true, true, 00, "SCOUT                            Maybe be a little extra careful  with that fire power of yours in this next part, huh?"},
                {fals, fals, 0,  "COM: Endscene"}
            };
        dialogue_page(lc);
        return 0;
        }

        case 34: {

            if (true) {
                line lc[32] = {
                    {fals, fals, 0,  "S07:06"},  
                    {fals, fals, 0,  "BG: fadeout"},
                    {true, true, 00, "MAPLE                            ..."},
                    {true, true, 00, "MAPLE                            What... the actual heck am I     looking at right now?"},
                    {true, true, 00, "S07:07"},
                    {true, true, 00, "BG: rain"},
                    {true, true, 00, "RUFUS                            Ichabod Williams and             Maple Tremblay, what a surprise! Fancy seeing you two here."},
                    {true, true, 00, "RUFUS                            Finally, I've got a full set."},
                    {true, true, 00, "S07:08"},
                    {true, true, 00, "SCOUT                            RUFUS THI-, WHAT ARE YOU DOING?"},
                    {true, true, 00, "MAPLE                            LET ME GO, YOU PUNK!"},
                    {true, true, 00, "RUFUS                            I suppose it won't be a bad idea to clap a magic-proof wristband  to keep you from getting any...  sparks of inspiration."},
                    {true, true, 00, "BG: fadeout"},
                    {true, true, 00, "S07:14"},
                    {true, true, 00, "RUFUS                            Alright, now that we've got all  three Tremblays in one place,    let's get started, shall we?"},
                    {true, true, 00, "S07:07"},
                    {fals, fals, 0,  "COM: Endscene"}
                };
                dialogue_page(lc);
                return 0;
            }

            if (true) {
                line lc[32] = {
                    {true, true, 00, "BG: groovy"},
                    {true, true, 00, "RUFUS                            Firstly, let's have an           introduction. I'm Monsieur Rufus Thibodeaux, and I'm going to be  your professor today."},
                    {true, true, 00, "RUFUS                            Pay attention - no one ever seemsto pay attention to  me, so therewill definitely be a quiz at the end of today's lecture."},
                    {true, true, 00, "S07:10"},
                    {true, true, 00, "RUFUS                            Lesson one. Repeat after me,     'Rufus is not short. He is just  small-boned.'"},
                    {true, true, 00, "MAPLE                            .....Are you /kidding/ me?"},
                    {true, true, 00, "RUFUS                            That doesn't sound very much likethe prompt, does it, Maple?"},
                    {true, true, 00, "S07:11"},
                    {true, true, 00, "RUFUS                            Everyone fails that section.     Moving on... Let's talk about theApres Flower. I was employed by  a certain company to"},
                    {true, true, 00, "RUFUS                            study this flower - same as our  dear Ichadod.. er.. 'Scout',     here. If you remember, it's both native here and known"},
                    {true, true, 00, "RUFUS                            to contain unknown 'metaphysical'properties. Neat, huh? So,       despite my instructions, I felt  bored and decided to"},
                    {true, true, 00, "RUFUS                            have myself a little chompy-chompof some of the leaves. Do you    know what happened after that?"},
                    {true, true, 00, "S07:12"},
                    {true, true, 00, "RUFUS                            Within moments, I found myself   traveling through the multiverse.I explored all sorts of differentworlds, some similar"},
                    {true, true, 00, "RUFUS                            and others very different to     ours, but do you know what I     discovered in nearly every one?"},
                    {true, true, 00, "S07:13"},
                    {true, true, 00, "RUFUS                            There was this strange trend of  strong-willed, conventionally    attractive women who seemed to   act as the moral good"},
                    {true, true, 00, "RUFUS                            and savior of every world, with  strange-looking men serving as   the butt of every joke, or as    incompetant villains"},
                    {true, true, 00, "RUFUS                            only to be replaced by the much  more competant, misunderstood    female villains who were only badbecause a man somehow"},
                    {true, true, 00, "RUFUS                            turned them evil. And you know   what I thought?"},
                    {true, true, 00, "MAPLE                            Hold on-"},
                    {true, true, 00, "S07:14"},
                    {true, true, 00, "MAPLE                            Are you literally telling me thatyou've decided to become a super villain because you took a flowerthat told you that"},
                    {true, true, 00, "MAPLE                            women are always the good guys,  and so you're going to harrass   our island?"},
                    {true, true, 00, "S07:16"},
                    {true, true, 00, "RUFUS                            I believe that by taking a pre-  emptive strike, I can manage to  keep my respect and autonomy     intact, yes."},
                    {fals, fals, 0,  "COM: Endscene"}
                };
                dialogue_page(lc);
                return 0;
            }

            if (true) {
                line lc[32] = {
                    {true, true, 00, "S07:15"},
                    {true, true, 00, "ENOKI                            Monsieur Rufus, may I go to the  restroom?"},
                    {true, true, 00, "S07:16"},
                    {true, true, 00, "RUFUS                            You can go after the lecture, I'malmost done."},
                    {true, true, 00, "S07:17"},
                    {true, true, 00, "RUFUS                            Now, as I was saying...."},
                    {true, true, 00, "BG: fadeout"},
                    {true, true, 00, "S07:16"},
                    {true, true, 00, "AARON                            Rufus, let's have a talk."},
                    {true, true, 00, "S07:18"},
                    {true, true, 00, "AARON                            First off, I'm surprised you     didn't know my wife was a        magician, she's good at getting  out of tight spaces."},
                    {true, true, 00, "AARON                            Secondly, I don't care what you  say when you ate that flower, youscared a lot of my friends. Bad."},
                    {true, true, 00, "AARON                            That's completely unacceptable.  You can't just kidnap people, or drill under their property, or   hold them hostage."},
                    {true, true, 00, "AARON                            Let us go and leave us alone,    c'est bon? Got it?"},
                    {true, true, 00, "RUFUS                            I'll tell you what. The two of   us have a little fight. You win, and I leave your island alone."},
                    {true, true, 00, "RUFUS                            I win, and you have to eat a     little bit of Apres, and we'll   see if you join my side. Oui?"},
                    {true, true, 00, "RUFUS                            Game on."},
                    {fals, fals, 0,  "COM: Endscene"}
                };
                dialogue_page(lc);
                return 0;
            }
        }

        case 35: {
            if (true) {
                line lc[32] = {
                    {true, true, 00, "RUFUS                            HA! Looks like I'm the victor    here. It's Apres flower time."},
                    {true, true, 00, "MAPLE                            You know what? In your dreams,   you little punk."},
                    {true, true, 00, "RUFUS                            Who you calling little?"},
                    {true, true, 00, "MAPLE                            You're standing on your tiptoes."},
                    {true, true, 00, "MAPLE                            Look, I don't know why you're so obsessed with thinking the       world's supposed to work a       certain way."},
                    {true, true, 00, "MAPLE                            But life is complicated, alright?Everybody's complicated. I don't care what you saw in that flower,but you can't just"},
                    {true, true, 00, "MAPLE                            Come in and bother all of us, whoare just chilling out, because   you think that-"},
                    {true, true, 00, "MAPLE                            Ok, y'all can stop snickering    whenever you want."},
                    {true, true, 00, "RUFUS                            But you don't-"},
                    {true, true, 00, "MAPLE                            I'll threaten you again like I   threaten everybody else-         any funny business, and-"},
                    {true, true, 00, "RUFUS                            I know, I know, I know, you'll   burn my face off."},
                    {true, true, 00, "MAPLE                            Darn straight."},
                    {true, true, 00, "CESAR                            Hey, Maple?"},
                    {true, true, 00, "MAPLE                            NOT NOW CESAR, I'M MESSING WITH ALITTLE PUNK, HERE!"},
                    {fals, fals, 0,  "COM: Endscene"}
                };
                dialogue_page(lc);
                return 0;
            }

            if (true) {
                line lc[32] = {
                    {true, true, 00, "GUY                              It's nice out here."},
                    {true, true, 00, "DIANA                            You're telling me. Honestly if itwasn't so expensive, I'd just    boat around 24/7."},
                    {true, true, 00, "GUY                              You think we gonna get any       tourists?"},
                    {true, true, 00, "DIANA                            Okay, I don't know if this is    just you, but you need to chill  out about your restaraunt."},
                    {true, true, 00, "DIANA                            You need to learn when to take a break and relax, oui?"},
                    {true, true, 00, "GUY                              I guess so. It's like my baby    though. I'm crazy about it."},
                    {true, true, 00, "DIANA                            I mean, what if something        happened, though? Like, what if  it blew up?"},
                    {true, true, 00, ""},
                    {true, true, 00, "GUY                              ..."},
                    {true, true, 00, "DIANA                            ..."},
                    {true, true, 00, "GUY                              Thunder... my... dog."},
                    {fals, fals, 0,  "COM: Endscene"}
                };
                dialogue_page(lc);
                return 0;
            }

            if (true) {
                line lc[32] = {
                    {true, true, 00, "RUFUS                            What the..."},
                    {true, true, 00, "RUFUS                            ..."},
                    {true, true, 00, "MAPLE                            I... I-I..."},
                    {true, true, 00, "AARON                            Maple, I-"},
                    {true, true, 00, "MAPLE                            ...I-I'm..."},
                    {true, true, 00, "ENOKI                            Maple, come back!"},
                    {true, true, 00, "MAPLE                            *sniff sniff*"},
                    {true, true, 00, "AARON                            Maple, get up."},
                    {true, true, 00, "MAPLE                            ..."},
                    {true, true, 00, "AARON                            Maple, we need to talk.          Right now."},
                    {true, true, 00, "ENOKI                            Maple, it's-"},
                    {true, true, 00, "AARON                            Maria, I love you, but it needs  to just be Maple and I."},
                    {true, true, 00, "ENOKI                            Maria... Alright Aaron, I'll go  check on the others."},
                    {true, true, 00, "AARON                            Maple, you need to get up and    look me in the eyes."},
                    {true, true, 00, "MAPLE                            G-Go away."},
                    {true, true, 00, "AARON                            GET UP!"},
                    {true, true, 00, "MAPLE                            O-Oui."},
                    {true, true, 00, "AARON                            Maple. We've needed to have this talk for a very long time and it can't wait.."},
                    {true, true, 00, "AARON                            I think you know what it's about."},
                    {true, true, 00, "MAPLE                            I d-don't want to talk right now."},
                };
                dialogue_page(lc);
                return 0;
            }

            if (true) {
                line lc[32] = {
                    {true, true, 00, "AARON                            Ever since high school, you've.. well, you know well enough."},
                    {true, true, 00, "AARON                            I can't fault you for everything.Maria is the best thing that has ever happened to me."},
                    {true, true, 00, "AARON                            I would have never met her if it wasn't for you. And I want you toknow that you're my sister."},
                    {true, true, 00, "AARON                            I'll always love you, okay? But  you... you've got this anger     inside of you all of the time."},
                    {true, true, 00, "AARON                            Anger isn't a bad thing, but     everything you're angry about..  it's all stuff YOU do."},
                    {true, true, 00, "AARON                            You're a miserable person to be  around and you make everyone elsesuffer because of it."},
                    {true, true, 00, "AARON                            Get over yourself."},
                    {true, true, 00, "AARON                            And Rufus, I believe I have a    deal to take care of."},
                    {true, true, 00, "ENOKI                            A-Aar.. AARON, WAIT!"},
                    {true, true, 00, "AARON                            I have to stay true to my word."},
                    {true, true, 00, "RUFUS                            Hey, chill, I didn't expect to   actually blow up your island-"},
                    {true, true, 00, "AARON                            The flower. Hand it over. Now."},
                    {true, true, 00, "ENOKI                            A-Aaron..? How do you feel?"},
                    {true, true, 00, "AARON                            I paid off the island in cash. Weshould easily have enough to renta house back in Louisiana."},
                    {true, true, 00, "AARON                            A cajun isn't home outside of    Louisiana anyway, oui?"},
                    {true, true, 00, "AARON                            Eleanor, Olivier, I'm sorry for  what happened to your home."},
                    {true, true, 00, "OLIVIER                          C'est bon. We're just happy to besafe. Easy come, easy go."},
                    {true, true, 00, "RUFUS                            I-I can help if anyone needs     anything or anywhere to stay."},
                };
                dialogue_page(lc);
                return 0;
            }

            if (true) {
                line lc[32] = {
                    {true, true, 00, "SCOUT                            Maple, how are you doing?"},
                    {true, true, 00, "MAPLE                            ..."},
                    {true, true, 00, "MAPLE                            ...Don't you dare give me any    pity, are we clear?"},
                    {true, true, 00, "SCOUT                            Y-Yeah, of course, I just.. I'm  sorry for-"},
                    {true, true, 00, "MAPLE                            What are YOU sorry for?"},
                    {true, true, 00, "SCOUT                            Please just let me finish."},
                    {true, true, 00, "MAPLE                            Okay. Go on."},
                    {true, true, 00, "SCOUT                            I.. I'm sorry for being forward, but please don't beat yourself   up. I'm on your side, right?"},
                    {true, true, 00, "MAPLE                            What, are you going to ask me outor something?"},
                    {true, true, 00, "SCOUT                            No, I- I.. well, no, I wasn't    going to.. look, I just don't    want you to go."},
                    {true, true, 00, "SCOUT                            Please don't go somewhere far    away because you feel bad."},
                    {true, true, 00, "MAPLE                            ...I won't, Scout. Don't worry."},
                    {fals, fals, 0,  "COM: Endscene"}
                };
                dialogue_page(lc);
                return 0;
            }

            if (true) {
                line lc[32] = {
                    {true, true, 00, "Following the distruction of the island, many of the islanders    decided to part ways. "},
                    {true, true, 00, "They kept in touch over the yearsbut some drifted farther away    than others."},
                    {true, true, 00, "Olivier and Eleanor moved into a small town in Ontario. Olivier   worked for a nearby farm, while  Eleanor continued to practice    magic at home."},
                    {true, true, 00, "Guy Pizza went back into the     pizza business, but this time    took it a little more seriously, eventually owning his own pizza  place."},
                    {true, true, 00, "Diana was infatuated with sailingand decided to take over Old Man Nicholas' ferrying business. She still operates it to this day."},
                    {true, true, 00, "Cesar left the country after someold clients managed to track him down. No one knows where he is   but Enoki, just in case she needsa legal represenative."},
                    {true, true, 00, "However, as for the others..."},

                    {true, true, 00, "ENOKI                            Hey, Maple! Back home so early?"},
                    {true, true, 00, "MAPLE                            Yep. The interview went great.   The military is going to suck,   but... the benefits are nice."},
                    {true, true, 00, "AARON                            You're gonna do great, Maple."},
                    {true, true, 00, "MAPLE                            You really think so?"},
                    {true, true, 00, "AARON                            You'll be the only elf on the    team, I bet. That's a huge       advantage."},
                    {true, true, 00, "MAPLE                            Yeah, I guess so. I talked to    Scout about it, he's happy enoughbut he says he'll miss me."},
                    {true, true, 00, "ENOKI                            We will too."},
                    {true, true, 00, "MAPLE                            You guys better have your own    place by the time I'm back,      though."},
                    {true, true, 00, "ENOKI                            Oh, we will, cuz, uh... Well,    I've got some news, too."},
                    {true, true, 00, "MAPLE                            Oh dear, what?"},
                    {true, true, 00, "ENOKI                            It's looking like we.. uh.. theremight be another Tremblay here   soon enough."},
                    {true, true, 00, "MAPLE                            Hold on, you're not-?"},
                    {true, true, 00, "ENOKI                            Uh huh!"},
                    {true, true, 00, "MAPLE                            You're PREGNANT?"},
                    {true, true, 00, "AARON                            Yes, ma'am."},
                    {true, true, 00, "ENOKI                            Ugh.. 2000 has been such a great year, I bet 2001 will be even    better!"},
                    {true, true, 00, "MAPLE                            Holy cow, I-.. I'm gonna be an   aunt. An Aaron-Enoki mix, what's that even going to be like?"},
                    {true, true, 00, "ENOKI                            I guess we're gonna see! You knowhow lucky I am, oui? So, I'm     thinking it's gonna be a girl,"},
                    {true, true, 00, "ENOKI                            And you know, if it's a girl, I'mgoing to name her-"},
                    {fals, fals, 0,  "COM: Endscene"}
                };
                dialogue_page(lc);
                return 0;
            }

            if (true) {
                line lc[32] = {
                    {true, true, 00, "ENOKI                            Télesphore, it's time to eat!"},
                    {true, true, 00, "TELES                            Coming!"},
                    {true, true, 00, "ENOKI                            Télesphore, say bonjour to your  everyone, new year's dinner is   almost ready."},
                    {true, true, 00, "TELES                            Bonjour, vous-autres."},
                    {true, true, 00, "SCOUT                            Hey, man! Melanie and Yves are   outside by the fire pit if you   were looking for 'em."},
                    {true, true, 00, "TELES                            Merci."},
                    {true, true, 00, "AARON                            Hey, y'all."},
                    {true, true, 00, "MAPLE                            Car ride wasn't bad. I brought   some gumbo."},
                    {true, true, 00, "ENOKI                            Well, you had better. I'm almost done myself."},
                    {true, true, 00, "ENOKI                            It's so nice to have Télesphore  home from college for Christmas, and now y'all?"},
                    {true, true, 00, "MAPLE                            It's really nice to check in. I'mtrying to get Melanie into       college."},
                    {true, true, 00, "MAPLE                            They just.. grow up so fast, you know? I know that's cliche."},
                    {true, true, 00, "AARON                            You're telling us? Hehe."},
                    {true, true, 00, "DEL                              I hope we're not bothering       anything, are we?"},
                    {true, true, 00, "ENOKI                            DELPHINE! RUFUS! YOU'RE HERE!"},
                    {true, true, 00, "RUFUS                            Hey guys, it's been a while."},
                    {true, true, 00, "ENOKI                            Perfect timing! You couldn't havegotten here any sooner."},
                    {true, true, 00, "ENOKI                            Happy New Years', y'all."},
                    {true, true, 00, "                                 - LA FIN -"},
                    {fals, fals, 0,  "COM: Endscene"}
                };
                dialogue_page(lc);
                return 0;
            }
        }

        default: {
            return 1;
            break;
        }
    }
}