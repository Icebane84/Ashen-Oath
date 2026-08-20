// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSerafinaEmpathicPostProcessAdapter.generated.h"

/**
 * UAshenSerafinaEmpathicPostProcessAdapter
 * Post-process adapter driving warm chromatic bloom during transference and desaturated haze under burnout.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSerafinaEmpathicPostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenSerafinaEmpathicPostProcessAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Visuals")
	void ApplyEmpathicTransferenceBloom(bool bIsTransferenceActive, float BurnoutLevel);
};
