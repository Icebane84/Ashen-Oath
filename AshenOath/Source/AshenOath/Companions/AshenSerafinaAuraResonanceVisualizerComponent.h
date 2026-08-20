// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenSerafinaAuraResonanceVisualizerComponent.generated.h"

/**
 * UAshenSerafinaAuraResonanceVisualizerComponent
 * Visualizes Serafina support aura emissive brightness based on SerafinaTrust.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSerafinaAuraResonanceVisualizerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSerafinaAuraResonanceVisualizerComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Companions")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Companions")
	float GetAuraBrightness() const { return AuraBrightness; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|Companions")
	float AuraBrightness = 1.0f;
};
