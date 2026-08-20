// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenFinisherGASCompanionTrustAdapter.generated.h"

/**
 * UAshenFinisherGASCompanionTrustAdapter
 * Awards companion trust (+0.15) on frame-perfect socket snapping and cooperative ability completion.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenFinisherGASCompanionTrustAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenFinisherGASCompanionTrustAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companions")
	float EvaluateFinisherGASTrustPayout(FName AbilityName, FName CompanionID);
};
