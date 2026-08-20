// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenCampfireInteractiveActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCampfireLitSignature, FName, CampfireID, float, HeatRadius);

/**
 * AAshenCampfireInteractiveActor
 *
 * Interactive World Actor for campfires enabling Camp behavior inspections and Memory Palace access.
 */
UCLASS()
class ASHENOATH_API AAshenCampfireInteractiveActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenCampfireInteractiveActor();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Campfire")
	void IgniteCampfire(float HeatRadius = 500.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Campfire|Events")
	FOnCampfireLitSignature OnCampfireLit;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Campfire")
	bool bIsLit = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Campfire")
	FName CampfireID;
};
