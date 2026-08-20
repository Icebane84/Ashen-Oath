// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenPhysicalJournalPropActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnJournalPropOpened);

/**
 * AAshenPhysicalJournalPropActor
 * Physical 3D actor in the game world with mesh, inspectable at campfires and Heartstones.
 */
UCLASS()
class ASHENOATH_API AAshenPhysicalJournalPropActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenPhysicalJournalPropActor();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Journal")
	FOnJournalPropOpened OnJournalPropOpened;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Journal")
	bool bIsJournalOpen = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Journal")
	void OpenJournalProp();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Journal")
	void CloseJournalProp();
};
