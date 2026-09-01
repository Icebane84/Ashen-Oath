stateDiagram-v2
    [*] --> IdleStance : Guard Initialized
    
    state IdleStance {
        [*] --> VomTag
        [*] --> Ochs
        [*] --> Pflug
        [*] --> Alber
        [*] --> Schrankhut
    }

    IdleStance --> ExecuteAttackRequest : Player Input Triggered
    
    state ExecuteAttackRequest {
        [*] --> FootworkEvaluation
        FootworkEvaluation --> PassingStep : If Vom Tag / Strike Forward
        FootworkEvaluation --> TriangleStep : If Ochs / Angle Counter
        FootworkEvaluation --> GatheringStep : If Pflug / Thrust Chase
        FootworkEvaluation --> BrokenStep : If Alber / Bait Lunge
    }

    ExecuteAttackRequest --> StrikeResolution : Active Frames Hitbox Active
    
    state StrikeResolution {
        [*] --> TargetGuardCheck
        TargetGuardCheck --> MasterCutCounterMatch : Correct Cut vs Guard Match
        TargetGuardCheck --> GenericParryBounce : Incorrect Cut vs Guard Match
        
        state MasterCutCounterMatch {
            [*] --> CleanBreach : Low Opponent Posture
            [*] --> WeaponBind_Indes : Strong Opponent Bind
        }
    }

    GenericParryBounce --> IdleStance : Reset to Baseline Stance
    CleanBreach --> OpponentStaggerState : Massive Posture Damage / Hit Confirmed
    OpponentStaggerState --> [*]

    state WeaponBind_Indes {
        [*] --> ProximityEvaluation
        ProximityEvaluation --> WindingThrust : Out of Close Range Reach
        ProximityEvaluation --> RingenAmSchwert : Proximity < Close Range Threshold
        
        state RingenAmSchwert {
            [*] --> Durchlaufen : From Alber Transition Up
            [*] --> Handdruecken : From Schrankhut Hilt Bind
            [*] --> EinhornHaken : From Einhorn Point Wind
            [*] --> KronRingen : From Krone Close Catch
        }
    }

    WindingThrust --> IdleStance : Reset / Long Point State
    RingenAmSchwert --> TakedownSuccessState : Grapple Input Successful
    RingenAmSchwert --> GrappleFailCounter : Grapple Input Missed / Escaped
    
    TakedownSuccessState --> OpponentGroundedState : Execute Finisher Window
    GrappleFailCounter --> IdleStance : Push Away Neutral State
    OpponentGroundedState --> [*]
