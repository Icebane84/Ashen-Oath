// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenMindscapeReconstructionManagerComponent.generated.h"

/**
 * UAshenMindscapeReconstructionManagerComponent
 * Manages psychic reconstruction mechanics, Resolve channel drain rates, and architectural integrity restoration.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenMindscapeReconstructionManagerComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenMindscapeReconstructionManagerComponent();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Memory")
	float ResolveDrainRatePerSecond = 15.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Memory")
	float CurrentReconstructionProgress = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Memory")
	bool AdvanceReconstruction(float DeltaSeconds, float AvailableResolve, float& OutRemainingResolve);
};
