#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "TwinStickShooterGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class TWINSTICKSHOOTER_API UTwinStickShooterGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec)
	void Host();
	
	UFUNCTION(Exec)
	void Join(const FString &Adress);
};
