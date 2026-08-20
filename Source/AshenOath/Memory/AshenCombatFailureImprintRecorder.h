// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenOath_ImprintBufferComponent.h"
#include "AshenCombatFailureImprintRecorder.generated.h"

/**
 * UAshenCombatFailureImprintRecorder
 *
 * Automatically records FPsychologicalImprint records on combat deaths, poise breaks, and near-death hits.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCombatFailureImprintRecorder : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCombatFailureImprintRecorder();

	/** Records a combat failure event into Kaelen's volatile imprint buffer */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Memory")
	void RecordCombatFailure(float DamageTaken, bool bWasFatal);
};
