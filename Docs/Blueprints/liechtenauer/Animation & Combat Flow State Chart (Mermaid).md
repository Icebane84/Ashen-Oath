# Animation & Combat Flow State Chart

This diagram illustrates the state transitions, guard mutations, Master Cut branching, and *Fühlen* bind resolutions for Kaelen's combat loop in *Ashen Oath*.

```mermaid
graph TD
    %% Base Stances
    subgraph Stances ["The Four Primary Guards (Vier Leger)"]
        VT["Vom Tag<br/>(High Roof Guard)"]
        OX["Ochs<br/>(High Window Guard)"]
        PF["Pflug<br/>(Low Plow Guard)"]
        AL["Alber<br/>(Low Fool's Guard)"]
        MH["Mordhau<br/>(Half-Sword / Inverted)"]
    end

    %% Master Cuts
    subgraph MasterCuts ["The Five Master Cuts (Die Fünf Meisterhaue)"]
        ZH["Zornhau (Wrath Cut)<br/>Diagonal Cleave"]
        KH["Krumphau (Crooked Cut)<br/>Crossed Wrists"]
        ZW["Zwerchhau (Thwart Cut)<br/>Horizontal False-Edge"]
        SH["Schielhau (Squinting Cut)<br/>Dipped-Point Counter"]
        SC["Scheitelhau (Crown Cut)<br/>Vertical Decapitation"]
        MO["Mordhau Strike<br/>Blunt Pommel Smash"]
    end

    %% Bind & Resolution States
    subgraph Fuhlen ["Fühlen (Tactile Blade Contact)"]
        WB["Weak Bind (Weich)<br/>Opponent yields pressure"]
        SB["Strong Bind (Hart)<br/>Opponent resists firmly"]
        ZO["Zorn-Ort Thrust<br/>Direct Centerline Plunge"]
        WN["Winden<br/>Winding to Upper Openings"]
        DP["Duplieren<br/>Double Strike Behind Guard"]
        MT["Mutieren<br/>Point Plunge to Lower Openings"]
    end

    %% Guard to Strike Connections
    VT -->|Light Attack| ZH
    VT -->|Heavy Attack| SC
    OX -->|Light Attack| ZW
    OX -->|Heavy Attack| KH
    PF -->|Light Attack| SH
    PF -->|Heavy Attack| PF_THRUST["Direct Thrust (Stich)"]
    MH -->|Light/Heavy Attack| MO

    %% Strike Clashes & Bind Routing
    ZH -->|Blade Clash| BIND_ZH{"Bind Pressure?"}
    BIND_ZH -->|Weak| ZO
    BIND_ZH -->|Strong| WN

    SH -->|Blade Clash| BIND_SH{"Bind Pressure?"}
    BIND_SH -->|Weak| PF_THRUST
    BIND_SH -->|Strong| DP

    SC -->|Blade Clash| BIND_SC{"Bind Pressure?"}
    BIND_SC -->|Strong Block| MT

    %% Flow Glint Recovery & Transitions
    ZH -->|Perfect Flow Glint (0 Stamina)| PF
    ZH -->|Perfect Flow Glint (0 Stamina)| OX
    KH -->|Perfect Flow Glint (0 Stamina)| VT
    ZW -->|Perfect Flow Glint (0 Stamina)| OX
    SH -->|Perfect Flow Glint (0 Stamina)| OX
    SC -->|Perfect Flow Glint (0 Stamina)| PF
    MO -->|Perfect Flow Glint (0 Stamina)| VT

    %% Style Formatting
    classDef stanceNode fill:#1a2332,stroke:#3b82f6,stroke-width:2px,color:#ffffff;
    classDef cutNode fill:#2c1b18,stroke:#ef4444,stroke-width:2px,color:#ffffff;
    classDef bindNode fill:#1c2d27,stroke:#10b981,stroke-width:2px,color:#ffffff;

    class VT,OX,PF,AL,MH stanceNode;
    class ZH,KH,ZW,SH,SC,MO,PF_THRUST cutNode;
    class WB,SB,ZO,WN,DP,MT,BIND_ZH,BIND_SH,BIND_SC bindNode;
```

---

## 🔁 Flow Glint Execution Legend

1. **White Line:** Direct input execution from guard into native Master Cut.
2. **Cyan Line:** Successful *Fühlen* blade-clash branching into winding (*Winden*), double strike (*Duplieren*), or mutation (*Mutieren*).
3. **Green Line:** $115\text{ BPM}$ ($0.15\text{s}$) **Perfect Flow Glint** transition refunding $100\%$ stamina and shifting Kaelen into the next Liechtenauer guard.
