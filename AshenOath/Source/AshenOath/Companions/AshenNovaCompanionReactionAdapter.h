// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenNovaCompanionReactionAdapter.generated.h"

/**
 * UAshenNovaCompanionReactionAdapter
 * Evaluates procedural hand tremor offsets for Serafina and perimeter defense locking for Garrett during Nova finisher execution.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenNovaCompanionReactionAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenNovaCompanionReactionAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companions")
	float CalculateSerafinaHandTremorOffset(float EmpathicBurnout) const;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companions")
	FName GetGarrettPerimeterStance() const;
};
