// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenCombatStanceTypes.h"
#include "AshenCombatStancePostProcessAdapter.generated.h"

/**
 * UAshenCombatStancePostProcessAdapter
 * Manages stance-specific visual post-process grading: radial motion blur (Berserk), cool steel tint (Aegis), prismatic lens flare (Flow).
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCombatStancePostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenCombatStancePostProcessAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Visuals")
	void ApplyStanceVisualGrading(ECombatStance Stance);
};
