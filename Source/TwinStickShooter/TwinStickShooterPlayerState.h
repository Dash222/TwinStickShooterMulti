#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "TwinStickShooterPlayerState.generated.h"


UCLASS()
class TWINSTICKSHOOTER_API ATwinStickShooterPlayerState : public APlayerState
{
	GENERATED_BODY()

private:

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	//UPROPERTY(ReplicatedUsing = OnRep_Name, BlueprintReadOnly, Category = TwinStickShooterPlayerState)
	UPROPERTY(Replicated, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	FString Name = "";


	UFUNCTION(Server, unreliable, WithValidation)
	void Server_SetName(const FString &NewName);
	void Server_SetName_Implementation(const FString &NewName);
	bool Server_SetName_Validate(const FString &NewName);
public:
	ATwinStickShooterPlayerState();
	UFUNCTION(BlueprintCallable)
	void SetName(const FString& NewName);

	virtual void CopyProperties(class APlayerState* PlayerState);
	virtual void OverrideWith(class APlayerState* PlayerState);
};
