// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCompanionDivergenceComponent.generated.h"

/**
 * UAshenCompanionDivergenceComponent
 * Dynamically scales navigation follow distance and flanking offsets based on trust and emotional divergence.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionDivergenceComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenCompanionDivergenceComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Companions")
	float FollowOffset = 300.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companions")
	float EvaluateNavigationOffset(FName CompanionID, float CompanionTrust, bool bIsIsolated);
};
