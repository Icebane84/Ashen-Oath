// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenEmpathicDialogueSaveGameAdapter.generated.h"

/**
 * UAshenEmpathicDialogueSaveGameAdapter
 * Core save adapter serializing unlocked dialogue branches.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenEmpathicDialogueSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenEmpathicDialogueSaveGameAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Core")
	bool SerializeDialogueState(int32 UnlockedBranchCount);
};
