// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenResonanceAnchoringComponent.generated.h"

/**
 * UAshenResonanceAnchoringComponent
 * Evaluates tripartite emotional sync (|SerafinaTrust - GarrettTrust| < 0.15, Fatigue < 0.40, Resolve > 0.50) and manages Resonance bonuses.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenResonanceAnchoringComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenResonanceAnchoringComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Companions")
	bool bIsResonanceActive = false;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Companions")
	float ResonanceDamageBonus = 0.15f; // +15% damage bonus

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companions")
	bool EvaluateResonanceSync(float GarrettTrust, float SerafinaTrust, float GarrettFatigue, float SerafinaFatigue, float Resolve);
};
