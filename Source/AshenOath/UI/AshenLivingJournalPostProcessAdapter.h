// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenLivingJournalPostProcessAdapter.generated.h"

/**
 * UAshenLivingJournalPostProcessAdapter
 * Manages post-process depth-of-field background blur during journal inspection and warm parchment focal lighting.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenLivingJournalPostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenLivingJournalPostProcessAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Visuals")
	void ApplyJournalInspectionPostProcess(bool bIsJournalOpen, float BlurWeight);
};
