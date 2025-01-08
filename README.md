# Fantasy Football (but somehow even more luck-based than usual)
*I based team formatting and scoring on [ESPN's](https://www.espn.com/fantasy/football/) default

Fantasy football is a weekly matchup of two teams of 16 players, 9 of whom start and whose points are counted. Players can be of 6 types:
- Quarterback: Earn points from passing yards and passing touchdowns.
- Wide Receiver: Earn points from receptions, receiving yards, and receiving touchdowns.
- Running Back: Earn points from rushing yards and rushing touchdowns.
- Tight Ends: Earn points from receptions, receiving yards, and receiving touchdowns.
- Defense/Special Teams: Earn points from few points allowed, few passing yards allowed, interceptions, sacks, fumble recoveries, and pick-sixes, and fumble recovery touchdowns.
- Kicker: Earn points from field goals made based on distance and extra points made.

The 9 starting slots on the team are the only points that count toward the matchup. Each slot can only be filled by certain types of players:
- QB: Quarterback
- RB: Running Back
- RB: Running Back
- WR: Wide Receiver
- WR: Wide Receiver
- TE: Tight End
- Flex: Running Back, Wide Receiver, or Tight End
- D/ST: Defense/Special Teams
- K: Kicker

There are also 7 bench slots to store players in reserve and a slot for an injured player.

However, there are extra-skilled players who can do more than is generally expected from their position. In these cases, they get special denominations:
Quarterback: Multi-threat; has the ability to get out of the pocket and get rushing yards and rushing touchdowns.
Wide Receiver: Multi-threat; has the ability to occasionally take hand-offs for rushing yards and rushing touchdowns.
Running Back: Multi-threat; has the ability to catch check-downs or run short routes for receptions, receiving yards, and receiving touchdowns.
Tight Ends: Multi-threat; some teams have a swiss army knife who can do everything offensively, usually listed as a tight end.
Defense/Special Teams: Spectacular Special Teams; some teams have return specialists who are able to get points from punt/kickoff return touchdowns and tenacious kick rushers who are able to block kicks.
Kicker: Limitless range; has the ability to kick 60+ yard field goals and has a higher accuracy on 50-59 yard field goals.

This code will allow a user to draft a fantasy football team and then make changes to it before each matchup with the opponent. The draft will be done in 16 rounds with the user able to state the position they wish to draft each round. Afterward the user will be able to:
Switch players from the bench into the starting lineup and vice versa
See their record and what week it is (the season is 18 weeks long)
After 18 weeks either victory, defeat, or a tie will be announced

Instead of being based on stats from real games like actual fantasy football, points will be generated via random number generation algorithmically based on draft position and opponenet being faced. There is a higher chance of “booming” (getting above expectations) when facing a lower-ranked opponent and a higher chance of “busting” (falling below expectations) when facing a higher-ranked opponent.

TLDR: Satiate your fantasy football addiction in the offseason by drafting an [ESPN](https://www.espn.com/fantasy/football/) default settings fantasy football team and simulate 18 weekly matchups against the same opponent

Array to store players and the team:
| Index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| Position | QB | RB | RB | WR | WR | TE | Flex | D/ST | K | B | B | B | B | B | B | B

# Class Hierarchy
* Football Player
  * Quarterback
  * Running Back
  * Wide Receiver/Tight End
  * Defense/Special Teams
  * Kicker
 
# How to play

Download everything, put it all in the same directory, then run main.cpp.

# Possible Extensions (working on it)

- More than two teams in the league
- Have the opponent's team be generated through the draft process with random number generation instead of pre-made in a text file
- Multi-user interface (play with friends)?
- Finish fixing team-editing features and UI navigation (game logs, profiles, etc...)
- Add more intricate algorithm for booming and busting as well as positional upgrades (Multi-Threat players, Limitless Range kickers, Spectacular Special Teams)
