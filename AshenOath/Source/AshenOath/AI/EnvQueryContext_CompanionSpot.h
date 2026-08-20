// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryContext.h"
#include "EnvQueryContext_CompanionSpot.generated.h"

/**
 * UEnvQueryContext_CompanionSpot
 *
 * EQS context providing PAA V2.1-aware tactical candidate locations for companion AI:
 *   - OffensiveSupport / TacticalTriage: Lateral flank positions 300-500uu offset from enemy.
 *   - UnchainedContainment: Enemy movement path intercept for trap placement.
 *   - RecoveryAnchoring: Cover/high-ground anchor within 600uu of Kaelen for Sanctuary ward.
 *
 * Reads the querying actor's UAshenCompanionAIComponent state to dispatch the correct
 * candidate location set to the EQS runner.
 */
UCLASS()
class ASHENOATH_API UEnvQueryContext_CompanionSpot : public UEnvQueryContext
{
	GENERATED_BODY()

public:
	virtual void ProvideContext(FEnvQueryInstance& QueryInstance, FEnvQueryContextData& ContextData) const override;

private:
	/** Returns lateral flank positions offset from the enemy for offensive/triage states. */
	void ProvideFlanкSpots(FEnvQueryInstance& QueryInstance, FEnvQueryContextData& ContextData) const;

	/** Returns enemy movement path intercept locations for trap placement. */
	void ProvideTrapSpots(FEnvQueryInstance& QueryInstance, FEnvQueryContextData& ContextData) const;

	/** Returns cover positions near Kaelen for Sanctuary ward anchoring. */
	void ProvideSanctuaryAnchorSpots(FEnvQueryInstance& QueryInstance, FEnvQueryContextData& ContextData) const;
};
