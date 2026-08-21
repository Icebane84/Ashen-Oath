/**
 * soul_kernel.js — Ashen Oath Psychological Runtime Kernel Mirror
 * 
 * Direct JavaScript translation of the 28-byte C++ FSoulStateVector memory contract
 * defined in ENGINE-SPEC-001.
 */

class SoulStateVector {
    constructor() {
        this.resolve = 1.0;         // 0.0 - 1.0 (Player Willpower)
        this.corruption = 0.0;      // 0.0 - 1.0 (Shadow Infiltration)
        this.isolation = 0.0;       // 0.0 - 1.0 (Fellowship Estrangement)
        this.garrettTrust = 0.5;    // 0.0 - 1.0 (Garrett Relational Bond)
        this.serafinaTrust = 0.5;   // 0.0 - 1.0 (Serafina Relational Bond)
        this.integrationDebt = 0.0; // 0.0 - 1.0 (Unprocessed Combat Trauma)
        this.lens = 0.0;            // Active Cognitive Filter Index
    }

    /**
     * Calculates the mean fellowship coherence index (0.0 to 1.0).
     */
    getFellowshipCoherence() {
        const avgTrust = (this.garrettTrust + this.serafinaTrust) / 2.0;
        const penalty = (this.corruption * 0.4) + (this.isolation * 0.3) + (this.integrationDebt * 0.3);
        return Math.max(0.0, Math.min(1.0, avgTrust - penalty));
    }

    /**
     * Evaluates the active Somatic State profile.
     */
    getSomaticState() {
        if (this.integrationDebt >= 0.70 || this.corruption >= 0.70) {
            return "DestabilizingCrisis";
        }
        if (this.integrationDebt >= 0.30 || this.isolation >= 0.40) {
            return "TraumaticAftermath";
        }
        return "Contemplative";
    }

    /**
     * Packs the soul state vector into a 28-byte Float32Array binary buffer.
     */
    toBytes() {
        const buffer = new Float32Array(7);
        buffer[0] = this.resolve;
        buffer[1] = this.corruption;
        buffer[2] = this.isolation;
        buffer[3] = this.garrettTrust;
        buffer[4] = this.serafinaTrust;
        buffer[5] = this.integrationDebt;
        buffer[6] = this.lens;
        return buffer;
    }
}

if (typeof module !== 'undefined' && module.exports) {
    module.exports = { SoulStateVector };
}
