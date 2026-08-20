// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenHallucinationCompanionReactivityAdapter.generated.h"

/**
 * UAshenHallucinationCompanionReactivityAdapter
 * Companions call out to Kaelen when noticing him swinging at empty air or walking into phantom walls.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenHallucinationCompanionReactivityAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenHallucinationCompanionReactivityAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Narrative")
	void TriggerCompanionConcernCallout(FName CompanionID, FString IllusionContext);
};
