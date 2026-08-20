// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenHallucinationPostProcessAdapter.generated.h"

/**
 * UAshenHallucinationPostProcessAdapter
 * Drives severe spatial static, double-vision lens shifts, and void-flickering chasms.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenHallucinationPostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenHallucinationPostProcessAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void ApplyHallucinatoryPostProcess(uint8 StateEnum, float Severity);
};
