// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenGarrettTacticalTrustAdapter.generated.h"

/**
 * UAshenGarrettTacticalTrustAdapter
 * Scales grapple rescue frequency based on pairwise trust band.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenGarrettTacticalTrustAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenGarrettTacticalTrustAdapter();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Companions")
	float InterposeRescueChance = 0.5f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companions")
	void UpdateTacticalTrustScaling(float GarrettTrustScore);
};
