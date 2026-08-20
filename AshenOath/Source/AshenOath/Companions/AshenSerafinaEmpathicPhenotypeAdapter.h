// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSerafinaEmpathicPhenotypeAdapter.generated.h"

/**
 * UAshenSerafinaEmpathicPhenotypeAdapter
 *
 * Maps SerafinaTrust & Resolve to Serafina's protective aura shielding frequency.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSerafinaEmpathicPhenotypeAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSerafinaEmpathicPhenotypeAdapter();

	/** Updates Serafina's support aura frequency */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Companions")
	void UpdateSerafinaBehavior(float SerafinaTrust, float Resolve);

	/** Returns support frequency multiplier */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Companions")
	float GetSupportFrequencyMultiplier() const { return SupportFrequencyMultiplier; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|Companions")
	float SupportFrequencyMultiplier = 1.0f;
};
