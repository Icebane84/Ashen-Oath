// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenJournalInkBleedMPCModulator.generated.h"

/**
 * UAshenJournalInkBleedMPCModulator
 * Drives MPC_JournalNyxBile dynamic material parameters for spreading black vein soot-stains on parchment.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenJournalInkBleedMPCModulator : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenJournalInkBleedMPCModulator();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Materials")
	FName InkBleedParameterName = "NyxBileVeinIntensity";

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Materials")
	void UpdateJournalInkBleedMaterial(float DebtLevel);
};
