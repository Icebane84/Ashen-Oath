// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenMindscapeCollapseVolume.generated.h"

class UBoxComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMindscapeCollapseTriggeredSignature, AActor*, TriggeringPawn, float, DebtLevel);

/**
 * AAshenMindscapeCollapseVolume
 *
 * Trigger volume monitoring player Integration Debt.
 * When player enters with Integration Debt >= 1.0 (EIntegrationDebtStage::ForcedCollapse),
 * triggers involuntary Mindscape transition and spawns psychological manifestation enemies.
 */
UCLASS()
class ASHENOATH_API AAshenMindscapeCollapseVolume : public AActor
{
	GENERATED_BODY()

public:
	AAshenMindscapeCollapseVolume();

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Mindscape")
	TObjectPtr<UBoxComponent> BoxComponent;

	UFUNCTION()
	void OnOverlapBegin(
		UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);

	// --- Delegates ---
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Mindscape|Events")
	FOnMindscapeCollapseTriggeredSignature OnMindscapeCollapseTriggered;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Mindscape")
	bool bTriggered = false;
};
