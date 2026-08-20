// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenLivingOathSubsystem.h"
#include "AshenOathCompanionTrustAdapter.generated.h"

/**
 * UAshenOathCompanionTrustAdapter
 * Modulates companion pairwise trust scores based on active oath adherence or oathbreaker fracture.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenOathCompanionTrustAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenOathCompanionTrustAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companions")
	float EvaluateOathTrustImpact(EAshenLivingOathType OathType, bool bOathFulfilled, FName CompanionID);
};
