// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenSerafinaAuraBuffScaleModulatorComponent.generated.h"

/**
 * UAshenSerafinaAuraBuffScaleModulatorComponent
 * Scales Serafina's protective aura stat buff potency based on SerafinaTrust.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSerafinaAuraBuffScaleModulatorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSerafinaAuraBuffScaleModulatorComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Companions")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Companions")
	float GetBuffPotency() const { return BuffPotency; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|Companions")
	float BuffPotency = 1.0f;
};
