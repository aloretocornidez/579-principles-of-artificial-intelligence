# ECE 579 | Homework 1

Name: Alan Manuel Loreto Cornídez

<!-- ## Question -->


<!-- For the intersection problem discussed in class, please propose a brief concept -->
<!-- (1 page maximum) of how you would implement the traffic light control scheme in -->
<!-- a real-world environment. Please note that I would like to see a concept that -->
<!-- applies to more than just the example in class (for instance, how would you deal -->
<!-- with the issue when the coloring solution results in more than red/green -->
<!-- colors). -->

## Response

Assuming correct state machine logic, the first step of implementation would be
finding a way to translate the digital logic that we have created and implement
it in the real world. This means using traffic signals.

While the current system works in a very simplified situation, the real world is
much more complex. Implementation of a yellow light in the traffic signal would
further complicate the logic required to control this system.

When considering more parameters for optimization, such as the throughput of the
crossing, implementing sensors that detect the amount of vehicles that may be
waiting for their turn to cross may allow for better optimization of the time
that each light should be green. The inclusion of a left turn signal would also
involve the use of more logic to make sure that throughput pipelines are not
being squandered by a waste of time showing left turn arrows when there are no
cars present.

If the implementor wanted to take pedestrians into account, this would also
affect the timing for the traffic signals in a significant manner. Sensors would
have to be placed that can detect when a pedestrian is present, and additional
logic would have to be put in place to allow timings for the signals to change
accordingly.

Up to this point, we have increased the complexity of the system many times
over. From a simple state machine with less than 5 states, to a much larger
state machine that takes into account the green state of one intersection, the
changing state of another, the ability to change how quickly a system transitions
states. Our system is quickly growing...

After considering the most basic implementation of a crossing with slight
modifications to allow for better throughput of vehicles at the single crossing
and perhaps even considering the pedestrian, further optimization can take
place. This could be in the form of creating networks of traffic signals that
allow one large section of crossings to have green lights and then allow the
other cardinal crossings have their turn. This massively increases the
computation power needed to analyze the system and take appropriate action.

This exercise shows how even a system as simple as a road crossing can increase
to any amount of complexity desired by the engineer, so optimizing it can only
be done by looking at what parameters want to be optimized, because in the real
world factors may not always be ideal. Sometimes the priority is time to
completion, quality of the result, or the cost of development.
