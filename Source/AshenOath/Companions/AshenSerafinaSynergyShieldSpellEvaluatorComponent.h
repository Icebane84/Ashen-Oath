// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenSerafinaSynergyShieldSpellEvaluatorComponent.generated.h"

/**
 * UAshenSerafinaSynergyShieldSpellEvaluatorComponent
 * Selects companion defense barrier spell types based on Serafina Trust & party state.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSerafinaSynergyShieldSpellEvaluatorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSerafinaSynergyShieldSpellEvaluatorComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Companion")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Companion")
	FName SelectBarrierSpell(float PartyHealthPercent) const;

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|Companion")
	float SerafinaTrustLevel = 0.5f;
};
