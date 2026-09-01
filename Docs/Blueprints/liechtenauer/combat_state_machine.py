"""
Ashen Oath - Combat Logic Component
Implements Johannes Liechtenauer's 14th-Century Kunst des Fechtens (Grandmaster Framework).
Provides dynamic state transitions, guard modifiers, and master strike counter resolution.
"""

from enum import Enum, auto
from typing import Dict, List, Optional, Tuple

class GuardStance(Enum):
    VOM_TAG = auto()   # From the Roof
    OCHS = auto()      # Ox
    PFLUG = auto()     # Plow
    ALBER = auto()     # Fool
    LANGORT = auto()   # Long Point (Endpoint)
    NEUTRAL = auto()   # Transitionary State

class MasterCut(Enum):
    ZORNHAU = auto()     # Wrath Cut
    KRUMPHAU = auto()    # Crooked Cut
    ZWERCHHAU = auto()   # Thwart Cut
    SCHIELHAU = auto()   # Squinting Cut
    SCHEITELHAU = auto()  # Crown Cut

class BindStrength(Enum):
    WEAK = auto()   # Soft pressure, open to immediate thrusting (Vor)
    STRONG = auto() # Firm opposition, requires winding or mutation (Nach)

class LiechtenauerCombatEngine:
    def __init__(self):
        # Explicit Hard Counter Mapping Matrix
        self.counter_matrix: Dict[GuardStance, List[MasterCut]] = {
            GuardStance.VOM_TAG: [MasterCut.ZORNHAU, MasterCut.ZWERCHHAU],
            GuardStance.OCHS:    [MasterCut.KRUMPHAU, MasterCut.SCHIELHAU],
            GuardStance.PFLUG:   [MasterCut.SCHIELHAU],
            GuardStance.ALBER:   [MasterCut.SCHEITELHAU]
        }
        
    def resolve_attack_interaction(
        self, 
        kaelen_cut: MasterCut, 
        opponent_guard: GuardStance, 
        bind_intensity: BindStrength = BindStrength.WEAK
    ) -> Tuple[bool, float, str]:
        """
        Processes a hit interaction based on the historical interaction matrix.
        Returns: (is_counter_successful, posture_damage_multiplier, follow_up_state)
        """
        # Validate if Kaelen executed the authentic historical counter
        valid_counters = self.counter_matrix.get(opponent_guard, [])
        
        if kaelen_cut in valid_counters:
            return self._execute_master_counter(kaelen_cut, bind_intensity)
        
        # Default interaction if it is not an explicit hard-counter Master Cut
        return False, 1.0, "Standard Parry / Weapon Bounce"

    def _execute_master_counter(self, cut: MasterCut, bind: BindStrength) -> Tuple[bool, float, str]:
        """Handles unique state transitions for successfully applied Master Cuts."""
        if cut == MasterCut.ZORNHAU:
            follow_up = "Langort Thrust (Zornhau-Ort)" if bind == BindStrength.WEAK else "Winden (Winding to Face)"
            return True, 1.75, follow_up
            
        elif cut == MasterCut.KRUMPHAU:
            return True, 2.0, "Wechsel (De-escalate to Low Offline Guard)"
            
        elif cut == MasterCut.ZWERCHHAU:
            return True, 1.5, "Alternate Side Horizontal Zwerchhau Combo Loop"
            
        elif cut == MasterCut.SCHIELHAU:
            follow_up = "Plunging Face Thrust" if bind == BindStrength.WEAK else "Duplieren (Strike Behind Guard)"
            return True, 1.8, follow_up
            
        elif cut == MasterCut.SCHEITELHAU:
            return True, 1.9, "Mutieren (Plunge Point Downward into Lower Body Openings)"
            
        return False, 1.0, "Neutral"

# Example validation usage
if __name__ == "__main__":
    engine = LiechtenauerCombatEngine()
    print("--- Combat Engine Simulation ---")
    
    # Scenario: Enemy holds high guard, Kaelen hits them with a Wrath Strike
    success, dmg, state = engine.resolve_attack_interaction(MasterCut.ZORNHAU, GuardStance.VOM_TAG, BindStrength.WEAK)
    print(f"Kaelen Zornhau vs Enemy Vom Tag -> Success: {success}, Posture Damage: {dmg}x, Next State: {state}")
