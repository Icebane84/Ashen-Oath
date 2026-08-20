// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenUnchainedPostProcessAdapter.generated.h"

/**
 * UAshenUnchainedPostProcessAdapter
 * Blood-red peripheral vignette and dark chromatic aberration during Unchained Berserk.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenUnchainedPostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenUnchainedPostProcessAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Visuals")
	void ApplyUnchainedPostProcess(bool bIsBerserkActive, float BerserkIntensity);
};
